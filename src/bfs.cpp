#include <vector>
#include <queue>
#include "../include/grafo.h"

using namespace std;

// Define as cores
#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

void Grafo::bfs(){
    // Inicia um array, com uma cor para cada vertice, iniciados como branco (inexplorados)
    vector<int> cor(this->qtdVertices, BRANCO);
    // Vetor aonde serao salvas as arestas percorridas
    vector<int> bfsArestas;
    // Fila que armazena a ordem do vertices (a serem testados)
    queue<int> fila;
    // Lista de adjacencia do grafo
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->getLista();

    // Insere 0 na pilha e marca como cinza (descoberto)
    int origem = 0;
    fila.push(origem);
    cor[origem] = CINZA;

    // Marca o numero de vertices visitados a partir do 0
    int numVisitados = 0;
    // Enquanto a fila nao estiver vazia
    while(!fila.empty()){
        // Salvar o primeiro vertice da fila, iniciar contagem de seu grau, e remover da fila
        int u = fila.front();
        int grau = 0;
        fila.pop();
        // Para cada vizinho deste vertice
        for(auto vizinho : listaAdj[u]) {
            // O grau aumenta
            grau++;
            int id = vizinho.first;
            int v = vizinho.second.first;
            // Se esse vizinho for branco, inserir na fila
            if(cor[v] == BRANCO){
                cor[v] = CINZA;
                bfsArestas.push_back(id);
                fila.push(v);
            }
            // Se encontrar algum cinza, marcar o grafo como ciclo
            else if(!(this->executouDfs) and !(this->ciclo) and cor[v] == CINZA){
                this->ciclo = true;
            }
        }
        // Depois de percorrer todos os vizinhos do vertice, marcar como preto
        numVisitados++;
        cor[u] = PRETO;
        // Checar se seu grau é par, caso nao seja, salvar a informacao de que ele nao e eureliano
        if(!this->executouBfs and grau%2 !=0){
            this->eureliano = false;
        }
    }
    // Ao terminar a busca, se o numero de vertices encontrados nao é igual ao numero de vertices do grafo, ele nao e conexo
    if(this->conexo and numVisitados<qtdVertices and !this->executouConexo){
        this->conexo = false;
    }

    // Marcar a flag de execucao da bfs como true, e retorna as arestas percorridas
    this->executouBfs = true;
    this->bfsArestas = bfsArestas;
}

// Getter - Arestas da BFS
vector<int> Grafo::getBfsArestas(){
    // Se nao tiver executado a bfs, executar
    if(!(this->executouBfs)){
        this->bfs();
    }
    // Retornar as arestas percorridas pela bfs
    return this->bfsArestas;
}