#include <vector>
#include <iostream>
#include "../include/articulados.h"

using namespace std;

#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

int tempo;

void artiucladosDFS(int u, vector<vector<pair<int, pair<int, int>>>>& adj, int* discovery, int* low, int* parent, vector<bool>& articulation, int* cor) {
    cor[u] = CINZA;
    discovery[u] = low[u] = ++tempo;
    int filhos = 0;

    for (const auto& edge : adj[u]) {  // Percorre as arestas conectadas ao vértice u
        int v = edge.second.first; // Obtém o índice do vértice de destino a partir do segundo par

        if (cor[v] == BRANCO) { // v ainda não foi visitado
            filhos++;
            parent[v] = u;
            artiucladosDFS(v, adj, discovery, low, parent, articulation, cor);

            // Verifica se a subárvore de v pode se conectar a um ancestral de u
            low[u] = min(low[u], low[v]);

            // Condição 1: U é raiz e tem mais de um filho
            if (parent[u] == -1 && filhos > 1) {
                articulation[u] = true;
            }

            // Condição 2: U não é raiz e low[v] >= discovery[u]
            if (parent[u] != -1 && low[v] >= discovery[u]) {
                articulation[u] = true;
            }
        } else if (v != parent[u]) { // v já foi visitado e não é o pai de u
            low[u] = min(low[u], discovery[v]);
        }
    }

    cor[u] = PRETO;
}

vector<int> articulados(vector<vector<pair<int, pair<int, int>>>>& adj, int qtdVertices) {
    int* discovery = new int[qtdVertices];
    int* low = new int[qtdVertices];
    int* parent = new int[qtdVertices];
    int* cor = new int[qtdVertices];
    vector<bool> articulation(qtdVertices, false);
    tempo = 0;

    for (int i = 0; i < qtdVertices; i++) {
        cor[i] = BRANCO;
        parent[i] = -1;
    }

    for (int u = 0; u < qtdVertices; u++) {
        if (cor[u] == BRANCO) {
            artiucladosDFS(u, adj, discovery, low, parent, articulation, cor);
        }
    }

    vector<int> pontosDeArticulacao;
    for (int i = 0; i < qtdVertices; i++) {
        if (articulation[i]) {
            pontosDeArticulacao.push_back(i);
        }
    }

    // Liberar memória
    delete[] discovery;
    delete[] low;
    delete[] parent;
    delete[] cor;

    return pontosDeArticulacao;
}
