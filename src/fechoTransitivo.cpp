#include <vector>
#include <queue>
#include "../include/grafo.h"

using namespace std;

void Grafo::calculaFechoTransitivo(){
    // Inicia um vetor que salva, para cada vertice, se ele foi visitado ou nao
    vector<bool> visitadosBool(this->qtdVertices, false);
    // Vetor que salva o fecho transitivo (vertices alcancaveis)
    vector<int> fechoTransitivo;
    // Fila que armazena a ordem do vertices (a serem testados)
    queue<int> fila;
    // Lista de adjacencia do grafo
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->getLista();

    // Insere 0 na fila
    fila.push(0);
    // Inicia uma BFS a partir de 0, onde todos os vertices alcancaveis sao marcados como visitados
    // Enquanto a fila nao tiver vazia
    while(!fila.empty()){
        // Salvar qual o primeiro elemento, e remove-lo da fila
        int u = fila.front();
        fila.pop();
        // Para cada vizinho, se nao foi visitado, adicionar na fila para checar e marcar como visitado
        for(auto vizinho : listaAdj[u]){
            int v = vizinho.second.first;
            if(visitadosBool[v] == false){
                fila.push(v);
            }
            visitadosBool[v] = true;
        }
    }

    // Inserir o indice de todos os vertices salvos como visitados, no vetor de fecho
    for(int i = 0; i < this->qtdVertices; i++){
        if(visitadosBool[i] == true){
            fechoTransitivo.push_back(i);
        }
    }

    // Marca a flag de execucao do fecho como true, e retorna os vertices do fecho
    this->executoFechoTransitivo = true;
    this->fechoTransitivo = fechoTransitivo;
}

// Getter - Vertices do Fecho Transitivo
vector<int> Grafo::getFechoTransitivo(){
    // Se nao tiver executado o fecho transitivo, executar
    if(!(this->executoFechoTransitivo)){
        this->calculaFechoTransitivo();
    }
    // Retornar os vertices do fecho transitivo
    return this->fechoTransitivo;
}