#ifndef DFS_H
#define DFS_H

#include <vector>
#include <queue>

bool final(std::vector<int> cor, std::vector<std::pair<int, std::pair<int, int>>>& vizinhos);
std::vector<int> dfs(std::vector<std::vector<std::pair<int, std::pair<int, int>>>>& lista_adj, int qtdVertices);

#endif