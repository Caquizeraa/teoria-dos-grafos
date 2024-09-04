#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Grafo {
    private:
        // Dados Grafo
        int qtdVertices; int qtdArestas; bool tipoGrafo;
        vector<vector<pair<int, pair<int, int>>>> listaAdj;
        // Dados Funcoes
        // Conexo
        bool executouConexo; bool conexo; void calculaConexo();
        // Bipartido
        bool bipartido;
        // Eureliano
        bool eureliano;
        // Ciclo
        bool ciclo;
        // CompConexas
        int compConexas; int compFortementeConexas;
        // Articulados
        vector<int> articulacao;
        // Pontes
        int qtdPonte;
        // DFS
        bool executouDfs; vector<int> dfsArestas; void dfs();
        // BFS
        bool executouBfs; vector<int> bfsArestas; void bfs();
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
        bool getTipo();
        vector<int> getDfsArestas();
        vector<int> getBfsArestas();
        bool getCiclo();
        bool getEureliano();
        bool getConexo();
};

// Construtor
Grafo::Grafo(int qtdVertices, int qtdArestas, vector<vector<pair<int, pair<int, int>>>> listaAdj, bool tipoGrafo){
    // Constroi o grafo com base nas informacoes passadas
    this->qtdVertices = qtdVertices;
    this->qtdArestas = qtdArestas;
    this->listaAdj = listaAdj;
    this->tipoGrafo = tipoGrafo;
    // Inicializando flags
    this->executouDfs = false;
    this->executouBfs = false;
    this->executouConexo = false;
    // Inicializando dados das funcoes
    this->ciclo = false;
    this->conexo = true;
    this->eureliano = true;
}

// Getter - Lista de Adjacência
vector<vector<pair<int, pair<int, int>>>> Grafo::getLista(){
    return this->listaAdj;
}

// Getter - Tipo do Grafo
bool Grafo::getTipo(){
    return this->tipoGrafo;
}
