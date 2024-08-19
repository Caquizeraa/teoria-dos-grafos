#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

void topologica_visit(vector<vector<pair<int, pair<int, int>>>>& lista_adj, int u, int* cor, stack<int>& ordemTopologica) {
    cor[u] = CINZA;

    // Ordena os vizinhos para garantir a ordem lexicográfica
    sort(lista_adj[u].begin(), lista_adj[u].end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.second.first < b.second.first;
    });

    for (auto& vizinho : lista_adj[u]) {
        int v = vizinho.second.first;

        if (cor[v] == BRANCO) {
            topologica_visit(lista_adj, v, cor, ordemTopologica);
        }
    }

    cor[u] = PRETO;
    ordemTopologica.push(u); // Adiciona o vértice na pilha quando todos os vizinhos forem explorados
}

vector<int> ordenacao_topologica(vector<vector<pair<int, pair<int, int>>>> lista_adj, int qtdVertices) {
    int* cor = new int[qtdVertices];
    for (int i = 0; i < qtdVertices; i++) {
        cor[i] = BRANCO;
    }

    stack<int> ordemTopologica;

    for (int i = 0; i < qtdVertices; i++) {
        if (cor[i] == BRANCO) {
            topologica_visit(lista_adj, i, cor, ordemTopologica);
        }
    }

    vector<int> resultado;
    while (!ordemTopologica.empty()) {
        resultado.push_back(ordemTopologica.top());
        ordemTopologica.pop();
    }

    delete[] cor;
    return resultado;
}
