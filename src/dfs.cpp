#include <vector>
#include <iostream>
#include "../include/grafo.h"

using namespace std;

// Define as cores
#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

// Funcao que descobre se um vertice e ou nao final, com base nas cores de seus vizinhos
bool final(vector<int> cor, vector<pair<int, pair<int, int>>> vizinhos) {
    // Para cada vizinho
    for(auto vizinho : vizinhos){
        int v = vizinho.second.first;
        // Se algum for branco, para a execucao, retornando que o vertice é nao final
        if(cor[v] == BRANCO){
            return false;
        }
    }
    // Se percorreu todos os vizinhos, e nao encontrou um branco, retorna que ele e final  
    return true;
};

void Grafo::dfs() {
    // Inicia um array, com uma cor para cada vertice, iniciados como branco (inexplorados)
    vector<int> cor(this->qtdVertices, BRANCO);
    // Vetor aonde serao salvas as arestas percorridas
    vector<int> dfsArestas;
    // Pilha que armazena a ordem do vertices (a serem testados)
    vector<int> pilha;
    // Lista de adjacencia do grafo
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->getLista();

    // Insere 0 na pilha e marca como cinza (descoberto)
    int origem = 0;
    pilha.push_back(origem);
    cor[origem] = CINZA;
    
    // Enquanto a pilha nao estiver vazia
    while(!pilha.empty()) {
        // Pego o ultimo valor da pilha
        int u = pilha.back();
        // Se ele nao for final
        if(!final(cor, listaAdj[u])){
            // Inserir o primeiro vizinho branco dele na pilha (marcando como cinza)
            bool empilhou = false;
            for(auto vizinho : listaAdj[u]) {
                int id = vizinho.first;
                int v = vizinho.second.first;
                if(cor[v] == BRANCO and !empilhou) {
                    pilha.push_back(v);
                    cor[v] = CINZA;
                    dfsArestas.push_back(id);
                    empilhou = true;
                }
                // Se encontrar algum cinza, marcar o grafo como ciclo
                else if(!(this->executouDfs) and !(this->ciclo) and cor[v] == CINZA){
                    this->ciclo = true;
                }
            }
        } else {
            // Se o vertice for final, marcar como preto (fechado) e remover da pilha
            cor[u] = PRETO;
            pilha.pop_back();
        }
    }
    // Marca a flag de execucao da dfs como true, e retorna as arestas percorridas
    this->executouDfs = true;
    this->dfsArestas = dfsArestas;
};

// Getter - Arestas da DFS
vector<int> Grafo::getDfsArestas(){
    // Se nao tiver executado a dfs, executar
    if(!(this->executouDfs)){
        this->dfs();
    }
    // Retornar as arestas percorridas pela dfs
    return this->dfsArestas;
}