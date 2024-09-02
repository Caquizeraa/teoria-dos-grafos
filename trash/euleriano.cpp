#include "../include/euleriano.h"
#include "../include/conexo.h"
#include <iostream>
#include <vector>

using namespace std;

bool euleriano (vector<vector<pair<int, pair<int, int>>>>& listaAdj, int numVertice){
    
    if(!conexoNaoDir(listaAdj, numVertice)) return false;    

    for(auto& relacoes : listaAdj){
        int contVertice = 0;
        for (auto& vertice : relacoes)
        {
            contVertice++;
        }
        if (contVertice % 2 != 0)
        {
            return false;
        }
    }

    return true;
}