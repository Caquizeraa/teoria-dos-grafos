#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Grafo {
    private:
        // Dados Grafo
        int qtdVertices;
        int qtdArestas;
        vector<vector<pair<int, pair<int, int>>>> listaAdj;
        bool tipoGrafo;
        // Conexo
        bool conexo;
        // Bipartido
        bool bipartido;
        // Eureliano
        bool eureliano;
        // Ciclo
        bool ciclo;
        // CompConexas
        int compConexas;
        int compFortementeConexas;
        // Articulados
        vector<int> articulacao;
        // Pontes
        int qtdPonte;
        // DFS
        bool executouDfs;
        void dfs();
        vector<int> dfsArestas;
        // BFS
        bool executouBfs;
        void bfs();
        vector<int> bfsArestas;
        // AGM
        int agm;
        // Ordem Topologica
        vector<int> ordemTopologica;
        // Caminho Minimo
        int caminhoMinimo;
        // Fluxo Maximo
        int fluxoMaximo;
        // Fecho Transitivo
        vector<int> fechoTransitivo;
    public:
        // Construtor
        Grafo(int qtdVertices, int qtdArestas, vector<vector<pair<int, pair<int, int>>>> listaAdj, bool tipoGrafo);
        // Getters
        vector<vector<pair<int, pair<int, int>>>> getLista();
        vector<int> getDfsArestas();
        vector<int> getBfsArestas();
        bool getCiclo();
};

Grafo::Grafo(int qtdVertices, int qtdArestas, vector<vector<pair<int, pair<int, int>>>> listaAdj, bool tipoGrafo){
    this->qtdVertices = qtdVertices;
    this->qtdArestas = qtdArestas;
    this->listaAdj = listaAdj;
    this->tipoGrafo = tipoGrafo;
    this->executouDfs = false;
    this->executouBfs = false;
    this->ciclo = false;
}

vector<vector<pair<int, pair<int, int>>>> Grafo::getLista(){
    return this->listaAdj;
}
