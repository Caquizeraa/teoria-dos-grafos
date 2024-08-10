#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define BRANCO 0 // vertice nao descoberto
#define CINZA 1  // vertice descoberto
#define PRETO 2  // vertice fechado

int main(){
    int qtdVertices, qtdArestas;
    string tipoGrafo;
    cin >> qtdVertices >> qtdArestas >> tipoGrafo;

    int* cor = new int[qtdVertices];

    for(int i = 0; i <= qtdVertices; i++) {
        cor[i] = BRANCO;
    }

    // Inicialize lista_adj com o número de vértices
    vector<vector<pair<int, pair<int, int>>>> lista_adj(qtdVertices);

    for(int i = 0; i < qtdArestas; i++){
        int id, origem, destino, peso;
        cin >> id >> origem >> destino >> peso;
        lista_adj[origem].push_back(make_pair(id, make_pair(destino, peso)));
        if(tipoGrafo == "nao_direcionado"){
            lista_adj[destino].push_back(make_pair(id, make_pair(origem, peso)));
        }
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
    for(int id : arestas) {
        cout << id << " ";
    }
    cout << endl;

    delete[] cor;

    return 0;
}
