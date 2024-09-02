#include <vector>
#include <iostream>
#include "../include/dfs.h"

using namespace std;

#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

vector<int> ordenacao_topologica(vector<vector<pair<int, pair<int, int>>>> lista_adj, int qtdVertices) {
    vector<int> cor(qtdVertices, BRANCO);
    vector<int> ordem;
    for(int i = 0; i < qtdVertices; i++){
        if(cor[i] == BRANCO){
            vector<int> pilha;
            pilha.push_back(i);
            while(!pilha.empty()) {
                int u = pilha.back();
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
                }else {
                    cor[u] = PRETO;
                    ordem.insert(ordem.begin(), u);
                    pilha.pop_back();
                }
            }
        }
    }
    return ordem;
}