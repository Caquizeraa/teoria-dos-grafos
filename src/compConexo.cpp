#include <iostream>
#include <vector>
#include "../include/compConexo.h"
#include "../include/marcaVisitados.h"

using namespace std;

int compConexo(vector<vector<pair<int, pair<int, int>>>>& listaAdj, int numVertices){
    vector<bool> visitados(numVertices, false);
    int qtdComponentes = 0;

    for (int i = 0; i < numVertices; i++)
    {
        if (!visitados[i])
        {
            marcaVisitados(listaAdj, i, visitados);
            qtdComponentes++;
        }   
    }

    return qtdComponentes;
}