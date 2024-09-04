#include "../include/grafo.h"

using namespace std;

// Getter - Eureliano
bool Grafo::getEureliano(){
    // Como eureliano e calculado durante a bfs, se nao executou bfs, ira executar
    if(!(this->executouBfs)){
        this->bfs();
    }
    // Retorna eureliano
    return this->eureliano;
}