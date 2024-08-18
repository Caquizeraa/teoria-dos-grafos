#include <vector>
#include <queue>

using namespace std;

#define BRANCO 0 // vertice nao descoberto
#define CINZA 1  // vertice descoberto
#define PRETO 2  // vertice fechado

vector<int> arestas(vector<vector<pair<int, pair<int, int>>>> lista_adj, int qtdVertices, int qtdArestas){
    int* cor = new int[qtdVertices];
    for(int i = 0; i <= qtdVertices; i++) {
        cor[i] = BRANCO;
    }

    int origem = 0;
    queue<int> fila;
    vector<int> arestas;
    fila.push(origem);
    cor[origem] = CINZA;

    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        cor[u] = PRETO;

        for(auto& vizinho : lista_adj[u]) {
            int id = vizinho.first;
            int v = vizinho.second.first;

            if(cor[v] == BRANCO){
                cor[v] = CINZA;
                arestas.push_back(id);
                fila.push(v);
            }
        }
    }

    // Exibindo o vetor de arestas que foram percorridas na BFS
    return arestas;
}