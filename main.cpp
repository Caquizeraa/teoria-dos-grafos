#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include "include/prim.h"
#include "include/euleriano.h"
#include "include/conexo.h"
#include "include/compConexo.h"
#include "include/bfs.h"
#include "include/dfs.h"
#include "include/ciclo.h"


using namespace std;

int main(){
    cout << "Programa iniciado." << endl;
    int qtdVertices, qtdArestas;
    string tipoGrafo;
    cin >> qtdVertices >> qtdArestas >> tipoGrafo;

    // Inicialize lista_adj com o número de vértices
    vector<vector<pair<int, pair<int, int>>>> lista_adj(qtdVertices);

    for(int i = 0; i < qtdArestas; i++){
        int id, origem, destino, peso;
        cin >> id >> origem >> destino >> peso;
        lista_adj[origem].push_back(make_pair(id, make_pair(destino, peso)));
        if(tipoGrafo == "nao_direcionado"){
            lista_adj[destino].push_back(make_pair(id, make_pair(origem, peso)));
        }
    }

    for(size_t i = 0; i < lista_adj.size(); i++){
        cout<< "Origem " << i <<":"<<endl;
        for(size_t j = 0; j < lista_adj[i].size(); j++){
            cout<<" id_aresta: " << lista_adj[i][j].first
                 << " Destino: " << lista_adj[i][j].second.first
                 << " Peso: " << lista_adj[i][j].second.second << endl;
        }
        cout<<endl;
    }

    // Peso total da arvore geradora minima e a distancia do vertice 0 ao N-1
    /*int pesoTotal = 0;
    int caminhoMin = prim(lista_adj, qtdVertices, pesoTotal);
    cout << caminhoMin //Imprime o caminho mínimo entre vértice 0 e o N-1                      //NÃO TA FUNCIONANDO PRA GRAFO NAO CONEXO
    << endl << pesoTotal << endl; //Imprime o valor total da Árvore Geradora Mínima
    */ 

    //1 -Verificar se um grafo é conexo (para o caso de grafos orientados, verificar conectividade fraca.)   
    cout<<"1- ";
    bool ehConexo;
    ehConexo = conexoNaoDir(lista_adj, qtdVertices);
    cout << ehConexo << endl;

    //2 -Verificar se um grafo não-orientado é bipartido. 


    //3 -Verificar se um grafo qualquer é Euleriano.   
    cout<<"3- ";
    bool teste;
    teste = euleriano(lista_adj, qtdVertices);
    cout << teste << endl;

    //4 -Verificar se um grafo possui ciclo.
    cout<<"4- ";
    bool cicloVar;
    cicloVar = ciclo(lista_adj, qtdVertices);
    cout<<cicloVar<<endl;

    //5 -Calcular a quantidade de componentes conexas em um grafo não-orientado.
    cout<<"5- ";
    int qtdComp;
    qtdComp = compConexo(lista_adj, qtdVertices); 
    cout << qtdComp << endl;

    //6 -Calcular a quantidade de componentes fortemente conexas em um grafo orientado.

    //7 -Imprimir os vértices de articulação de um grafo não-orientado (priorizar a ordem lexicográfica dos vértices).    
    
    //8 -Calcular quantas arestas ponte possui um grafo não-orientado.    
    
    //9 -Imprimir a árvore em profundidade (priorizando a ordem lexicográfica dos vértices; 0 é a origem). Você deve imprimir o identificador das arestas. Caso o grafo seja desconexo, considere apenas a árvore com a raíz 0.   
    vector<int> arestasDfs = dfs(lista_adj, qtdVertices, qtdArestas);
    cout<<"9- ";
    for(int id : arestasDfs) {
        cout << id << " ";
    }
    cout<<endl;

    //10 -Árvore de largura (priorizando a ordem lexicográfica dos vértices; 0 é a origem). Você deve imprimir o identificador das arestas. Caso o grafo seja desconexo, considere apenas a árvore com a raíz 0.    
    vector<int> arestasBfs = bfs(lista_adj, qtdVertices, qtdArestas);
    cout<<"10- ";
    for(int id : arestasBfs) {
        cout << id << " ";
    }
    cout<<endl;

    //11 -Calcular o valor final de uma árvore geradora mínima (para grafos não-orientados).    
    
    //12 -Imprimir a ordem os vértices em uma ordenação topológica. Esta função não fica disponível em grafos não direcionado. Deve-se priorizar a ordem lexicográfica dos vértices.   
    
    //13 -Valor do caminho mínimo entre dois vértices (para grafos não-orientados com pelo menos um peso diferente nas arestas).  0 é a origem; n-1 é o destino.   
    
    //14 -Valor do fluxo máximo para grafos direcionados. 0 é a origem; n-1 é o destino.   
    
    //15 -Fecho transitivo para grafos direcionados.  Deve-se priorizar a ordem lexicográfica dos vértices; 0 é o vértice escolhido.

    //Verifica se é euleriano


    //Verifica quantos componentes conexos existem
    

    return 0;
}