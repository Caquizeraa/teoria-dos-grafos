#include <vector>
#include "../include/grafo.h"

using namespace std;

#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

bool final(vector<int> cor, vector<pair<int, pair<int, int>>> vizinhos) {
    for(auto vizinho : vizinhos){
        int v = vizinho.second.first;
        if(cor[v] == BRANCO){
            return false;
        }
    }
    return true;
};

void Grafo::dfs() {
    vector<int> cor(this->qtdVertices, BRANCO);
    vector<int> dfsArestas;
    vector<int> pilha;

    int origem = 0;
    pilha.push_back(origem);
    cor[origem] = CINZA;

    while(!pilha.empty()) {
        int u = pilha.back();
        if(!final(cor, this->listaAdj[u])) {
            for(auto vizinho : this->listaAdj[u]) {
                int id = vizinho.first;
                int v = vizinho.second.first;
                if(cor[v] == BRANCO) {
                    pilha.push_back(v);
                    cor[v] = CINZA;
                    dfsArestas.push_back(id);
                    break;
                }else if(!(this->executouBfs) and !(this->ciclo) and cor[v] == CINZA){
                    this->ciclo = true;
                }
            }
        } else {
            cor[u] = PRETO;
            pilha.pop_back();
        }
    }
    this->executouDfs = true;
    this->dfsArestas = dfsArestas;
};

vector<int> Grafo::getDfsArestas(){
    if(!(this->executouDfs)){
        this->dfs();
    }
    return this->dfsArestas;
}