#include <vector>
#include <queue>

using namespace std;

bool bfs_ciclo(vector<vector<pair<int, pair<int, int>>>> lista_adj, int origem, vector<int>& pais) {
    vector<bool> visitados(lista_adj.size(), false);
    queue<int> fila;

    fila.push(origem);
    visitados[origem] = true;
    pais[origem] = -1; // O vértice de origem não tem pai

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for (auto& vizinho : lista_adj[u]) {
            int v = vizinho.second.first;

            if (!visitados[v]) {
                fila.push(v);
                visitados[v] = true;
                pais[v] = u;
            } else if (v != pais[u]) {
                return true; // Encontrou um ciclo
            }
        }
    }

    return false;
}

bool ciclo(vector<vector<pair<int, pair<int, int>>>> lista_adj, int qtdVertices) {
    vector<int> pais(qtdVertices, -1);

    for (int i = 0; i < qtdVertices; i++) {
        if (pais[i] == -1) {
            if (bfs_ciclo(lista_adj, i, pais)) {
                return true; // Ciclo encontrado
            }
        }
    }

    return false; // Nenhum ciclo encontrado
}
