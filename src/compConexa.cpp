#include <vector>
#include <iostream>
#include "../include/grafo.h"

using namespace std;


// Define as cores
#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

// Funçao que calcula a quantidade de componentes conexas (executa em grafos nao direcionados)
void Grafo::calculaConexa(){
    // Inicia um array, com uma cor para cada vertice, iniciados como branco (inexplorados)
    vector<int> cor(this->qtdVertices, BRANCO);
    // Pilha que armazena a ordem do vertices (a serem testados)
    vector<int> pilha;
    // Lista de adjacencia do grafo
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->getLista();

    // Inicia a quantidade de componentes como zero
    int qtdComponentes = 0;
    // Faz uma dfs, para cada vertice branco
    for(int i = 0; i < this->qtdVertices; i++){
        if(cor[i] == BRANCO){
            // Insere o vertice na pilha e marca como cinza (descoberto)
            pilha.push_back(i);
            cor[i] = CINZA;
            // Enquanto a pilha nao estiver vazia
            while(!pilha.empty()) {
                // Pego o ultimo valor da pilha
                int u = pilha.back();
                // Se ele nao for final
                if(!final(cor, listaAdj[u])){
                    // Inserir o primeiro vizinho branco dele na pilha (marcando como cinza)
                    for(auto vizinho : listaAdj[u]) {
                        int id = vizinho.first;
                        int v = vizinho.second.first;
                        if(cor[v] == BRANCO) {
                            pilha.push_back(v);
                            cor[v] = CINZA;
                        }
                    }
                }else{
                    // Se o vertice for final, marcar como preto (fechado) e remover da pilha
                    cor[u] = PRETO;
                    pilha.pop_back();
                }
            }
            // Aumenta o contador de componente, sempre que a pilha esvazia 
            qtdComponentes++;
        }
    }
    // Retorna a quantidade de componentes
    this->compConexas = qtdComponentes;
}; 

void Grafo::calculaFortementeConexa(){
    int qtdComponentes = 0;
};

void Grafo::calculaCompConexa(){
    // Se ele for direcionado
    if(this->getTipo() == 0){
        // Calcula componentes fortemente conexas
        this->calculaFortementeConexa();
    }
    // Se o grafo for nao direcionado
    else{
        // Calcula componentes conexas
        this->calculaConexa();
    }
    this->executouCompConexa = true;
};

int Grafo::getCompConexa(){
    if(!this->executouCompConexa){
        this->calculaCompConexa();
    }
    return this->compConexas;
};