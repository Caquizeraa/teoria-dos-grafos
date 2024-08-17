#include <iostream>
#include <vector>
#include "../include/conexo.h"

using namespace std;

void marcaVisitados(vector<vector<pair<int, pair<int, int>>>>& listaAdj, int vertice, vector<bool>& visitados){
    visitados[vertice] = true;
    for (auto& elemento : listaAdj[vertice])
    {
        int vizinho = elemento.second.first;
        if (!visitados[vizinho])
        {
            marcaVisitados(listaAdj, vizinho, visitados);
        }
    }
}

bool conexoNaoDir(vector<vector<pair<int, pair<int, int>>>>& listaAdj, int numVertices){
    vector<bool> visitados(numVertices, false);
    marcaVisitados(listaAdj, 0, visitados);
    for (bool x : visitados)
    {
        if(x == false) return false;
    }
    return true;
}