#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <algorithm>
#include <queue>

class Grafo {
    private:
        int qtdVertices;
        int qtdArestas;
        std::vector<std::vector<std::pair<int,std:: pair<int, int>>>> listaAdj;
        bool tipoGrafo;
        bool conexo;
        bool bipartido;
        bool eureliano;
        bool ciclo;
        int compConexas;
        int compFortementeConexas;
        std::vector<int> articulacao;
        int qtdPonte;
        bool executouDfs;
        void dfs();
        std::vector<int> dfsArestas;
        bool executouBfs;
        void bfs();
        std::vector<int> bfsArestas;
        int agm;
        std::vector<int> ordemTopologica;
        int caminhoMinimo;
        int fluxoMaximo;
        std::vector<int> fechoTransitivo;
    public:
        Grafo(int qtdVertices, int qtdArestas, std::vector<std::vector<std::pair<int,std:: pair<int, int>>>> listaAdj, bool tipoGrafo);
        std::vector<std::vector<std::pair<int, std::pair<int, int>>>> getLista();
        std::vector<int> getDfsArestas();
        std::vector<int> getBfsArestas();
        bool getCiclo();
};
#endif
