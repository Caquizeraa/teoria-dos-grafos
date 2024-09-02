#include <iostream>
#include <vector>
#include <algorithm> 
#include "../include/compConexo.h"
#include "../include/marcaVisitados.h"
#include "../include/dfs.h"

using namespace std;

#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado


int compConexo(vector<vector<pair<int, pair<int, int>>>> listaAdj, int qtdVertices){
    vector<bool> visitados(qtdVertices, false);
    int qtdComponentes = 0;

    for (int i = 0; i < qtdVertices; i++)
    {
        if (!visitados[i])
        {
            marcaVisitados(listaAdj, i, visitados);
            qtdComponentes++;
        }   
    }

    return qtdComponentes;
}

int compFortementeConexo(vector<vector<pair<int, pair<int, int>>>> listaAdj, int qtdVertices){
    int componentes = 0;
    vector<vector<pair<int, pair<int, int>>>> inverso(qtdVertices);
    for(int i = 0; i < qtdVertices; i++){
        for(auto aresta: listaAdj[i]){
            int origem = i;
            int id = aresta.first;
            int destino = aresta.second.first;
            int peso = aresta.second.second;
            inverso[destino].push_back(make_pair(id, make_pair(origem, peso)));
        }
    }
    vector<int> out(qtdVertices);

    int qtdComponentes = 0;

    out = marcaTempos(listaAdj, qtdVertices);
    vector<pair<int,int>> outv(qtdVertices);
    sort(outv.begin(),outv.end(),ordenaPar);

    
    vector<int> cor(qtdVertices, BRANCO);

    for(int i = 0; i < qtdVertices; i++){
        if(cor[i] == BRANCO){
            vector<int> pilha;
            componentes++;
            pilha.push_back(i);
            while(!pilha.empty()) {
                int u = pilha.back();
                if(!final(cor, inverso[u])) {
                    for(auto& vizinho : inverso[u]) {
                        int id = vizinho.first;
                        int v = vizinho.second.first;
                        if(cor[v] == BRANCO) {
                            pilha.push_back(v);
                            cor[v] = CINZA;
                            break;
                        }
                    }
                }else {
                    cor[u] = PRETO;
                    pilha.pop_back();
                }
            }
        }
    }
    return componentes;
}



vector<int> marcaTempos(vector<vector<pair<int, pair<int, int>>>> lista_adj, int qtdVertices){
    vector<int> entrada(qtdVertices,0);
    vector<int> saida(qtdVertices,0);
    vector<int> cor(qtdVertices, BRANCO);
    vector<int> pilha;

    int origem = 0;
    int passos = 1;

    pilha.push_back(origem);
    cor[origem] = CINZA;

    while(!pilha.empty()) {
        int u = pilha.back();
        if(entrada[u]==0){
            entrada[u] = passos; 
            passos++;
        }
        if(!final(cor, lista_adj[u])) {
            for(auto& vizinho : lista_adj[u]) {
                int id = vizinho.first;
                int v = vizinho.second.first;
                if(cor[v] == BRANCO) {
                    pilha.push_back(v);
                    cor[v] = CINZA;
                    break;
                }
            }
        } else {
            cor[u] = PRETO;
            saida[u] = passos;
            passos++;
            pilha.pop_back();
        }
    }
    return saida;
}

bool ordenaPar(pair<int,int> a,pair<int,int> b){
       return a.second>b.second;
}