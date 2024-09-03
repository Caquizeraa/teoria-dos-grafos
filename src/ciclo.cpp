#include "../include/grafo.h"

using namespace std;

bool Grafo::getCiclo(){
    if(!(this->executouDfs) and !(this->executouBfs)){
        this->dfs();
    }
    return this->ciclo;
}