#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include "include/prim.h"

using namespace std;

int main(){
    cout << "Programa iniciado." << endl;
    int qtdVertices, qtdArestas;
    string tipoGrafo;
    cin >> qtdVertices >> qtdArestas >> tipoGrafo;

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

    for(size_t i = 0; i < lista_adj.size(); i++){
        cout<< "Origem " << i <<":"<<endl;
        for(size_t j = 0; j < lista_adj[i].size(); j++){
            cout<<" id_aresta: " << lista_adj[i][j].first
                 << " Destino: " << lista_adj[i][j].second.first
                 << " Peso: " << lista_adj[i][j].second.second << endl;
        }
        cout<<endl;
    }

    int pesoTotal = 0;
    int caminhoMin = prim(lista_adj, qtdVertices, pesoTotal);
    cout << caminhoMin //Imprime o caminho mínimo entre vértice 0 e o N-1
    << endl << pesoTotal; //Imprime o valor total da Árvore Geradora Mínima

    return 0;
}