#ifndef TOPOLOGICA_H
#define TOPOLOGICA_H

#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

std::vector<int> ordenacao_topologica(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> lista_adj, int qtdVertices);

#endif