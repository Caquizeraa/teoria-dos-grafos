#include <vector>
#include <iostream>
#include "../include/grafo.h"

using namespace std;

// Funcao que calcula se um grafo e ou nao conexo
void Grafo::calculaConexo(){
    // Se ele for direcionado
    if(this->getTipo() == 0){
        // Um grafo auxiliar, que e a transposicao do grafo original para nao direcionado, e criado
        vector<vector<pair<int, pair<int, int>>>> listaAdj = this->getLista();
        vector<vector<pair<int, pair<int, int>>>> listaAux(this->qtdVertices);
        for(int i = 0; i < this->qtdVertices; i++){
            for(auto aresta : listaAdj[i]){
                int id = aresta.first; 
                int origem = i;
                int destino = aresta.second.first; 
                int peso = aresta.second.second;
                listaAux[origem].push_back(make_pair(id, make_pair(destino, peso)));
                listaAux[destino].push_back(make_pair(id, make_pair(origem, peso)));
            }
        }
        Grafo* grafoAux = new Grafo(this->qtdVertices, this->qtdArestas, listaAux, 1);
        // Se o grafo auxiliar for conexo, o grafo atual e fracamente conexo
        this->conexo = grafoAux->getConexo();
    }
    // Se o grafo for nao direcionado
    else{
        // Se nao executou a bfs, executar, pois ela calcula se um grafo nao direcionado e ou nao conexo
        if(!(this->executouBfs)){
            this->bfs();
        }
    }
    // Setar a flag de execucao de calcula conexo para true
    this->executouConexo = true;
}

// Getter - Conexo
bool Grafo::getConexo(){
    // Se nao calculou o conexo, calcular
    if(!executouConexo){
        this->calculaConexo();
    }
    // Retorna conexo
    return this->conexo;
}
