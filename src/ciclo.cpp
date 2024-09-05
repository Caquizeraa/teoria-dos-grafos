#include "../include/grafo.h"

using namespace std;

// Getter - Ciclo
bool Grafo::getCiclo(){
    // Como ciclos podem ser encontrados em ambas as buscas (bfs e dfs), se nenhuma foi executada, execute dfs (poderia ser bfs)
    if(!(this->executouCiclo)){
        this->dfs();
    }
    // Retorna ciclo
    return this->ciclo;
}