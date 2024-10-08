#include <vector>
#include "../include/grafo.h"

using namespace std;

// Define as cores
#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

void Grafo::dfs(int origem/*= 0*/) {
    // Inicia um array, com uma cor para cada vertice, iniciados como branco (inexplorados)
    vector<int> cor(this->qtdVertices, BRANCO);
    // Vetor aonde serao salvas as arestas percorridas
    vector<int> dfsArestas;
    // Pilha que armazena a ordem do vertices (a serem testados)
    vector<int> pilha;
    // Lista de adjacencia do grafo
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->getLista();

    // Insere 0 na pilha e marca como cinza (descoberto)
    pilha.push_back(origem);
    cor[origem] = CINZA;

    // Marca o numero de vertices visitados a partir do 0
    int numVisitados = 0;
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
                else if(!(this->executouCiclo) and !(this->ciclo) and cor[v] == CINZA){
                    this->ciclo = true;
                    this->executouCiclo = true;
                }
            }
        } else {
            // Se o vertice for final, marcar como preto (fechado) e remover da pilha
            numVisitados++;
            cor[u] = PRETO;
            pilha.pop_back();
        }
    }

    if(this->conexo and numVisitados<qtdVertices and !this->executouConexo and !this->executouBfs){
        this->conexo = false;
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