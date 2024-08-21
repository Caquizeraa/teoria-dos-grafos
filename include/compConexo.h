#ifndef COMPCONEXO_H
#define COMPCONEXO_H

#include <vector>
#include <utility>

int compConexo(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> listaAdj, int qtdVertices);
int compFortementeConexo(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> listaAdj,int qtdVertices);
std::vector<int> marcaTempos(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> lista_adj, int qtdVertices);
bool ordenaPar(std::pair<int,int> a,std::pair<int,int> b);

#endif