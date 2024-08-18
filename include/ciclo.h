#ifndef CICLO_H
#define CICLO_H

#include <vector>
#include <queue>

bool ciclo(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> lista_adj, int qtdVertices);
bool bfs_ciclo(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> lista_adj, int origem, std::vector<int>& pais);

#endif