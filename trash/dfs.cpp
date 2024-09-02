#include <vector>
#include <iostream>

using namespace std;

#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

bool final(vector<int> cor, vector<pair<int, pair<int, int>>>& vizinhos) {
    for(auto& vizinho : vizinhos){
        int v = vizinho.second.first;
        if(cor[v] == BRANCO){
            return false;
        }
    }
    return true;
}

vector<int> dfs(vector<vector<pair<int, pair<int, int>>>>& lista_adj, int qtdVertices) {
    vector<int> cor(qtdVertices, BRANCO);
    vector<int> arestas;
    vector<int> pilha;

    int origem = 0;

    pilha.push_back(origem);
    cor[origem] = CINZA;

    while(!pilha.empty()) {
        int u = pilha.back();
        if(!final(cor, lista_adj[u])) {
            for(auto& vizinho : lista_adj[u]) {
                int id = vizinho.first;
                int v = vizinho.second.first;
                if(cor[v] == BRANCO) {
                    pilha.push_back(v);
                    cor[v] = CINZA;
                    arestas.push_back(id);
                    break;
                }
            }
        } else {
            cor[u] = PRETO;
            pilha.pop_back();
        }
    }

    return arestas;
}