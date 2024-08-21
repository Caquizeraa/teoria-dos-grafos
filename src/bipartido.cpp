#include <iostream>
#include <vector>
#include <queue>
#include "../include/bipartido.h"

using namespace std;

#define BRANCO 0 //Ainda não visitado
#define PRETO 1  //Pintado de preto
#define VERMELHO 2 //Pintado de vermelho

bool bipartido(vector<vector<pair<int, pair<int, int>>>>& listaAdj, int qtdVertices){
    vector<int> cor(qtdVertices, BRANCO);
    for (int i = 0; i < qtdVertices; i++)
    {
        if(cor[i] == BRANCO){ 
            cor[i] = PRETO;
            queue<int> fila;
            fila.push(i);

            while (!fila.empty())
            {
                int verticeAtual = fila.front();
                fila.pop();
                for(auto& vizinhos : listaAdj[verticeAtual]){
                    int vizinhoAtual = vizinhos.second.first;
                    if(cor[vizinhoAtual] == BRANCO){
                        if(cor[verticeAtual] == PRETO)cor[vizinhoAtual] = VERMELHO;
                        else cor[vizinhoAtual] = PRETO;
                        fila.push(vizinhoAtual);
                    }else if(cor[vizinhoAtual] == cor[verticeAtual]) return false;
                }
            }
        }
    }
    return true;
}