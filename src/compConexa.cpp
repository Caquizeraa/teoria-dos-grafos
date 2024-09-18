#include <vector>
#include "../include/grafo.h"

using namespace std;


// Define as cores
#define BRANCO 0 // vértice não descoberto
#define CINZA 1  // vértice descoberto
#define PRETO 2  // vértice fechado

// Funçao que calcula a quantidade de componentes conexas (executa em grafos nao direcionados)
void Grafo::calculaConexa(){
    // Inicia um array, com uma cor para cada vertice, iniciados como branco (inexplorados)
    vector<int> cor(this->qtdVertices, BRANCO);
    // Pilha que armazena a ordem do vertices (a serem testados)
    vector<int> pilha;
    // Lista de adjacencia do grafo
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->getLista();

    // Inicia a quantidade de componentes como zero
    int qtdComponentes = 0;
    // Faz uma dfs, para cada vertice branco
    for(int i = 0; i < this->qtdVertices; i++){
        if(cor[i] == BRANCO){
            // Insere o vertice na pilha e marca como cinza (descoberto)
            pilha.push_back(i);
            cor[i] = CINZA;
            // Enquanto a pilha nao estiver vazia
            while(!pilha.empty()) {
                // Pego o ultimo valor da pilha
                int u = pilha.back();
                // Se ele nao for final
                if(!final(cor, listaAdj[u])){
                    // Inserir o primeiro vizinho branco dele na pilha (marcando como cinza)
                    for(auto vizinho : listaAdj[u]) {
                        int id = vizinho.first;
                        int v = vizinho.second.first;
                        if(cor[v] == BRANCO) {
                            pilha.push_back(v);
                            cor[v] = CINZA;
                        }
                    }
                }else{
                    // Se o vertice for final, marcar como preto (fechado) e remover da pilha
                    cor[u] = PRETO;
                    pilha.pop_back();
                }
            }
            // Aumenta o contador de componentes, sempre que a pilha esvazia 
            qtdComponentes++;
        }
    }
    // Retorna a quantidade de componentes
    this->compConexas = qtdComponentes;
}; 

void Grafo::calculaFortementeConexa(){
    // Inicia a quantidade de componentes como zero
    int qtdComponentes = 0;
    // Lista de adjacencia do grafo
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->getLista();
    // Lista de adjacencia do grafo inverso (arestas mudam a direcao) é calculada
    vector<vector<pair<int, pair<int, int>>>> listaInversa(this->qtdVertices);
    for(int i = 0; i < qtdVertices; i++){
        for(auto aresta: listaAdj[i]){
            int origem = i;
            int id = aresta.first;
            int destino = aresta.second.first;
            int peso = aresta.second.second;
            listaInversa[destino].push_back(make_pair(id, make_pair(origem, peso)));
        }
    }
    // Grafo inverso é instanciado
    Grafo* inverso = new Grafo(this->qtdVertices, this->qtdArestas, listaInversa, this->tipoGrafo);
    
    // Vetor que salva tempos de saida ao executar um DFS no grafo inverso
    vector<int> temposInverso(this->qtdVertices, 0);
    // Inicia a contagem de tempo
    int tempo = 1;

    // Iniciando DFS simples para marcar os tempos do grafo inverso
    // Pilha que armazena a ordem do vertices (a serem testados)
    vector<int> pilha;
    // Inicia um array, com uma cor para cada vertice, iniciados como branco (inexplorados)
    vector<int> cor(this->qtdVertices, BRANCO);

    // Checa se sobrou algum vertice branco (fora da componente), para fazer uma DFS
    for(int i = 0; i < this->qtdVertices; i++){
        if(cor[i]==BRANCO){
            // Insere o vertice na pilha, marca como cinza (descoberto) e aumenta o tempo de entrada
            pilha.push_back(i);
            cor[i] = CINZA;
            tempo++;
            // Enquanto a pilha nao estiver vazia
            while(!pilha.empty()) {
                // Pego o ultimo valor da pilha
                int u = pilha.back();
                // Se ele nao for final
                if(!final(cor, listaInversa[u])) {
                    // Inserir o primeiro vizinho branco dele na pilha (marcando como cinza) e aumentar o tempo
                    for(auto& vizinho : listaInversa[u]) {
                        int id = vizinho.first;
                        int v = vizinho.second.first;
                        if(cor[v] == BRANCO) {
                            pilha.push_back(v);
                            tempo++;
                            cor[v] = CINZA;
                            break;
                        }
                    }
                } else {
                    // Se o vertice for final, marcar como preto (fechado), remover da pilha
                    cor[u] = PRETO;
                    // Salvar seu tempo de saida e aumentar o contador de tempo
                    temposInverso[u] = tempo;
                    tempo++;
                    pilha.pop_back();
                }
            }
        }
    }
    
    // Criar um vetor, que salva os indices e seu tempo de saida
    vector<pair<int,int>> tempoOrdem(qtdVertices);
    for(int i = 0; i< this->qtdVertices; i++){
        tempoOrdem[i] = make_pair(temposInverso[i], i);
    }
    
    // Ordenar este vetor com base no tempo de saida (de forma descrescente)
    sort(tempoOrdem.rbegin(), tempoOrdem.rend());

    // Resetar vetor de cores, para realizar uma nova DFS
    for(int i = 0; i<this->qtdVertices; i++){
        cor[i] = BRANCO;
    }

    // Para cada vertice, em ordem decrescente de tempo de fechamento
    for(auto vertice : tempoOrdem){
        int i = vertice.second;
        // Se esse vertice for branco, realizar uma DFS no grafo original
        if(cor[i] == BRANCO){
            pilha.push_back(i);
            cor[i] = CINZA;
            // Enquanto a pilha nao estiver vazia
            while(!pilha.empty()) {
                // Pego o ultimo valor da pilha
                int u = pilha.back();
                // Se ele nao for final
                if(!final(cor, listaAdj[u])){
                    // Inserir o primeiro vizinho branco dele na pilha (marcando como cinza)
                    for(auto vizinho : listaAdj[u]) {
                        int id = vizinho.first;
                        int v = vizinho.second.first;
                        if(cor[v] == BRANCO) {
                            pilha.push_back(v);
                            cor[v] = CINZA;
                        }
                    }
                }else{
                    // Se o vertice for final, marcar como preto (fechado) e remover da pilha
                    cor[u] = PRETO;
                    pilha.pop_back();
                }
            }
            // Aumenta o contador de componentes, sempre que a pilha esvazia 
            qtdComponentes++;
        }
    }
    // Retorna a quantidade de componentes
    this->compConexas = qtdComponentes;
};

void Grafo::calculaCompConexa(){
    // Se ele for direcionado
    if(this->getTipo() == 0){
        // Calcula componentes fortemente conexas
        this->calculaFortementeConexa();
    }
    // Se o grafo for nao direcionado
    else{
        // Calcula componentes conexas
        this->calculaConexa();
    }
    this->executouCompConexa = true;
};

int Grafo::getCompConexa(){
    if(!this->executouCompConexa){
        this->calculaCompConexa();
    }
    return this->compConexas;
};