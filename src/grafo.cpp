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
        bool executouCiclo; bool ciclo;
        // CompConexas
        bool executouCompConexa; int compConexas; void calculaCompConexa(); void calculaConexa(); void calculaFortementeConexa();
        // Articulados
        vector<int> articulacao;
        // Pontes
        int qtdPonte;
        // DFS
        bool executouDfs; vector<int> dfsArestas; void dfs(int origem = 0);
        // BFS
        bool executouBfs; vector<int> bfsArestas; void bfs(int origem = 0);
        // AGM
        int agm;
        // Ordem Topologica
        bool executouOrdemTopologica; vector<int> ordemTopologica; void calculaTopologica();
        // Caminho Minimo
        int caminhoMinimo;
        // Fluxo Maximo
        int fluxoMaximo;
        // Fecho Transitivo
        bool executoFechoTransitivo; vector<int> fechoTransitivo; void calculaFechoTransitivo();
        // Funcoes extras
        static bool final(vector<int> cor, vector<pair<int, pair<int, int>>> vizinhos); // Calcula se um vertice é final (nao tem vizinhos inexplorados)
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
        vector<int> getOrdemTopologica();
        int getCompConexa();
        vector<int> getFechoTransitivo();
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
    this->executouCiclo = false;
    this->executouOrdemTopologica = false;
    this->executouCompConexa = false;
    this->executoFechoTransitivo = false;
    // Inicializando dados das funcoes
    this->ciclo = false;
    this->conexo = true;
    this->eureliano = true;
    this->compConexas = 0;
}

// Getter - Lista de Adjacência
vector<vector<pair<int, pair<int, int>>>> Grafo::getLista(){
    return this->listaAdj;
}

// Getter - Tipo do Grafo
bool Grafo::getTipo(){
    return this->tipoGrafo;
}

// Funcao que descobre se um vertice e ou nao final, com base nas cores de seus vizinhos
bool Grafo::final(vector<int> cor, vector<pair<int, pair<int, int>>> vizinhos) {
    // Para cada vizinho
    for(auto vizinho : vizinhos){
        int v = vizinho.second.first;
        // Se algum for branco (0), para a execucao, retornando que o vertice é nao final
        if(cor[v] == 0){
            return false;
        }
    }
    // Se percorreu todos os vizinhos, e nao encontrou um branco, retorna que ele e final  
    return true;
};