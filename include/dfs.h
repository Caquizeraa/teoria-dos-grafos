#ifndef DFS_H
#define DFS_H

#include <vector>
#include <queue>

std::vector<int> dfs(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> lista_adj, int qtdVertices, int qtdArestas);
std::vector<int> dfs_visit(std::vector<std::vector<std::pair<int, std::pair<int, int>>>> lista_adj, int qtdVertices, int qtdArestas);

#endif