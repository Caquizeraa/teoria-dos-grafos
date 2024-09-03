#include <vector>
#include <queue>
#include "../include/grafo.h"

using namespace std;

#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

void Grafo::bfs(){
    vector<int> cor(this->qtdVertices, BRANCO);
    vector<int> bfsArestas;
    queue<int> fila;

    int origem = 0;
    fila.push(origem);
    cor[origem] = CINZA;

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        for(auto vizinho : this->listaAdj[u]) {
            int id = vizinho.first;
            int v = vizinho.second.first;
            if(cor[v] == BRANCO){
                cor[v] = CINZA;
                bfsArestas.push_back(id);
                fila.push(v);
            }else if(!(this->executouDfs) and !(this->ciclo) and cor[v] == CINZA){
                this->ciclo = true;
            }
        }
        cor[u] = PRETO;
    }
    this->executouBfs = true;
    this->bfsArestas = bfsArestas;
}

vector<int> Grafo::getBfsArestas(){
    if(!(this->executouBfs)){
        this->bfs();
    }
    return this->bfsArestas;
}