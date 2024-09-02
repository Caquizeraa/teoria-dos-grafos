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