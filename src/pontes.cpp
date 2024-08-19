#include <iostream>
#include <vector>
#include "../include/pontes.h"

using namespace std;

int pontes(vector<vector<pair<int, pair<int, int>>>>& listaAdj){
    int qtdPontes = 0;
    for(auto& vertice : listaAdj){
        int qntRelacoes=  0;
        for(auto& relacoes : vertice){
            qntRelacoes++;
        }
        if(qntRelacoes == 1) qtdPontes++;
    }

    return qtdPontes;
}