#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <algorithm>
#include <queue>

class Grafo {
    private:
        // Dados Grafo
        int qtdVertices; int qtdArestas; bool tipoGrafo;
        std::vector<std::vector<std::pair<int,std:: pair<int, int>>>> listaAdj;
        // Dados Funcoes
        // Conexo
        bool executouConexo; bool conexo; void calculaConexo(); 
        // Bipartido
        bool bipartido;
        // Eureliano
        bool eureliano;
        // Ciclo
        bool executouCiclo; bool ciclo;
        // CompConexas
        bool executouCompConexa; int compConexas; void calculaCompConexa(); void calculaConexa(); void calculaFortementeConexa();
        // Articulados
        std::vector<int> articulacao;
         // Pontes
        int qtdPonte;
        // DFS
        bool executouDfs; std::vector<int> dfsArestas; void dfs(int origem = 0);
        // BFS
        bool executouBfs; std::vector<int> bfsArestas; void bfs(int origem = 0);
        // AGM
        int agm;
        // Ordem Topologica
        bool executouOrdemTopologica; std::vector<int> ordemTopologica; void calculaTopologica();
        // Caminho Minimo
        int caminhoMinimo;
        // Fluxo Maximo
        int fluxoMaximo;
        // Fecho Transitivo
        std::vector<int> fechoTransitivo;
    public:
        // Construtor
        Grafo(int qtdVertices, int qtdArestas, std::vector<std::vector<std::pair<int,std::pair<int, int>>>> listaAdj, bool tipoGrafo);
        // Getters
        std::vector<std::vector<std::pair<int, std::pair<int, int>>>> getLista();
        bool getTipo();
        std::vector<int> getDfsArestas();
        std::vector<int> getBfsArestas();
        bool getCiclo();
        bool getEureliano();
        bool getConexo();
        std::vector<int> getOrdemTopologica();
        int getCompConexa();
        // Funcoes extras
        static bool final(std::vector<int> cor, std::vector<std::pair<int, std::pair<int, int>>> vizinhos); // Calcula se um vertice é final (nao tem vizinhos inexplorados)
};
#endif
