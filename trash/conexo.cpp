#include <iostream>
#include <vector>
#include "../include/conexo.h"
#include "../include/marcaVisitados.h"

using namespace std;

bool conexoNaoDir(vector<vector<pair<int, pair<int, int>>>>& listaAdj, int numVertices){
    vector<bool> visitados(numVertices, false);
    marcaVisitados(listaAdj, 0, visitados);
    for (bool x : visitados)
    {
        if(x == false) return false;
    }
    return true;
}