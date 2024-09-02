#include "../include/dijkstra.h"
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int djikstra(vector<vector<pair<int, pair<int, int>>>>& listaAdj, int qtdVertices){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
    vector<int> distancia(qtdVertices, INT_MAX);

    min_heap.push(make_pair(0,0));
    distancia[0] = 0;

    while (!min_heap.empty())
    {
        int u = min_heap.top().second;
        min_heap.pop();

        for(auto& vizinho : listaAdj[u]){
            int v = vizinho.second.first;
            int peso = vizinho.second.second;

            if(distancia[u] + peso < distancia[v]){
                distancia[v] = distancia[u] + peso;
                min_heap.push(make_pair(distancia[v], v));
            }
        }
    }
    return distancia[qtdVertices-1];

}