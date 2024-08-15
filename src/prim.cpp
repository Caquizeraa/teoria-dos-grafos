#include "../include/prim.h"
#include <vector>
#include <queue>
#include <limits.h>


using namespace std;

int prim(vector<vector<pair<int, pair<int, int>>>>& listaAdj, int qtdVertices, int& pesoTotal){
    vector<int> key(qtdVertices, INT_MAX);
    vector<bool> inMST(qtdVertices, false);
    vector<int> pai(qtdVertices, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

    key[0] = 0;
    min_heap.push({0,0});

    while (!min_heap.empty())
    {
        int x = min_heap.top().second;
        min_heap.pop();

        inMST[x] = true;

        for (auto& relacao : listaAdj[x]) {
            int destino = relacao.second.first;
            int peso = relacao.second.second;
            if (peso && !inMST[destino] && peso < key[destino])
            {
                key[destino] = peso;
                min_heap.push({key[destino], destino});
                pai[destino] = x;
            }
        }
    }

    for (int i = 0; i < qtdVertices; i++)
    {
        if (pai[i] != -1)
        {
            pesoTotal += key[i];
        }
    }

    int soma_pesos = 0;
    int vertice = qtdVertices - 1;
    while (vertice != 0)
    {   
        int pai_vertice = pai[vertice];
        for (auto& relacao : listaAdj[pai_vertice])
        {
            if (relacao.second.first == vertice)
            {
                soma_pesos += relacao.second.second;
                break;
            }
        }
        vertice = pai_vertice;
    }
    return soma_pesos;
    
};