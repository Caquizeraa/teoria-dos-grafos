#include <vector>
#include <queue>

using namespace std;

#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

void dfs_visit(vector<vector<pair<int, pair<int, int>>>>& lista_adj, int u, int* cor, vector<int>& arestas) {
    cor[u] = CINZA;

    for (auto& vizinho : lista_adj[u]) {
        int id = vizinho.first;
        int v = vizinho.second.first;

        if (cor[v] == BRANCO) {
            arestas.push_back(id);
            dfs_visit(lista_adj, v, cor, arestas);
        }
    }

    cor[u] = PRETO;
}

vector<int> dfs(vector<vector<pair<int, pair<int, int>>>> lista_adj, int qtdVertices, int qtdArestas) {
    int* cor = new int[qtdVertices];
    for (int i = 0; i <= qtdVertices; i++) {
        cor[i] = BRANCO;
    }

    vector<int> arestas;
    int origem = 0;
    dfs_visit(lista_adj, origem, cor, arestas);

    // Exibindo o vetor de arestas que foram percorridas na DFS
    return arestas;
}
