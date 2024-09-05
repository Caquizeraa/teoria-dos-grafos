#include <vector>
#include "../include/grafo.h"

using namespace std;

// Define as cores
#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

void Grafo::calculaTopologica(){
    // Inicia um array, com uma cor para cada vertice, iniciados como branco (inexplorados)
    vector<int> cor(this->qtdVertices, BRANCO);
    // Vetor aonde serao salvos os vertices em ordem topologica
    vector<int> ordemTopologica;
    // Lista de adjacencia do grafo
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->getLista();

    // Para cada vertice do grafo, caso esteja branco, executar uma DFS a partir deste vertice
    for(int i = 0; i < this->qtdVertices; i++){
        if(cor[i] == BRANCO){
            // Executar uma DFS

            // Pilha que armazena a ordem do vertices (a serem testados)
            vector<int> pilha;
            // Inserir o vertice branco na pilha, para ser testado
            pilha.push_back(i);

            // Enquanto a pilha nao estiver vazia
            while(!pilha.empty()) {
                // Pego o ultimo valor da pilha
                int u = pilha.back();
                // Se ele nao for final
                if(!final(cor, listaAdj[u])) {
                    // Inserir o primeiro vizinho branco dele na pilha (marcando como cinza)
                    bool empilhou = false;
                    for(auto vizinho : listaAdj[u]) {
                        int id = vizinho.first;
                        int v = vizinho.second.first;
                        if(cor[v] == BRANCO and !empilhou) {
                            pilha.push_back(v);
                            cor[v] = CINZA;
                            empilhou = true;
                        }
                        // Se encontrar algum cinza, marcar o grafo como ciclo
                        else if(!(this->executouCiclo) and !(this->ciclo) and cor[v] == CINZA){
                            this->ciclo = true;
                            this->executouCiclo = true;
                        }
                    }             
                }
                else{
                    // Se o vertice for final, marcar como preto (fechado) e remover da pilha
                    cor[u] = PRETO;
                    pilha.pop_back();
                    // Inserir o vertice no inicio do vetor de ordem
                    ordemTopologica.insert(ordemTopologica.begin(), u);
                }
            }
        }
    }
    this->executouOrdemTopologica = true;
    this->ordemTopologica = ordemTopologica;
}

// Getter - OrdemTopologica
vector<int> Grafo::getOrdemTopologica(){
    // Se nao executou a ordem topologica, executar
    if(!this->executouOrdemTopologica){
        this->calculaTopologica();
    }
    return this->ordemTopologica;
}