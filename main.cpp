#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <sstream>
#include "include/prim.h"
#include "include/euleriano.h"
#include "include/conexo.h"
#include "include/compConexo.h"
#include "include/bfs.h"
#include "include/dfs.h"
#include "include/ciclo.h"
#include "include/topologica.h"
#include "include/pontes.h"
#include "include/bipartido.h"
#include "include/articulados.h"
#include "include/dijkstra.h"
#include "include/fechoTransitivo.h"
#include "include/compConexo.h"


using namespace std;

int main(){
    cout << "Programa iniciado." << endl;

    queue<int> questoes;
    string linha;

    getline(cin, linha);
    stringstream ss(linha);
    int numero;
    while (ss >> numero)
    {
        questoes.push(numero);
    }

    
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

    bool ehConexo, ehBipartido, teste, cicloVar;
    int qtdComp, qtdPontes, caminhoMin, qtdCompConex;
    vector<int> qtdArticulado, arestasDfs, arestasBfs, fecho;
    while(!questoes.empty()){
        int x = questoes.front();
        questoes.pop();
        switch(x){
            case 0:
                //1 -Verificar se um grafo é conexo (para o caso de grafos orientados, verificar conectividade fraca.)   
                cout<<"1- ";
                ehConexo = conexoNaoDir(lista_adj, qtdVertices);
                cout << ehConexo << endl;
                break;

            case 1:
                //2 -Verificar se um grafo não-orientado é bipartido. 
                cout <<"2- ";
                ehBipartido = bipartido(lista_adj, qtdVertices);
                cout << ehBipartido << endl;
                break;

            case 2:
                //3 -Verificar se um grafo qualquer é Euleriano.   
                cout<<"3- ";
                teste = euleriano(lista_adj, qtdVertices);
                cout << teste << endl;
                break;

            case 3:
                //4 -Verificar se um grafo possui ciclo.
                cout<<"4- ";
                cicloVar = ciclo(lista_adj, qtdVertices);
                cout<<cicloVar<<endl;
                break;

            case 4:
                //5 -Calcular a quantidade de componentes conexas em um grafo não-orientado.
                if (tipoGrafo != "direcionado")
                {
                    cout<<"5- ";
                    qtdComp = compConexo(lista_adj, qtdVertices); 
                    cout << qtdComp << endl;
                }else cout << -1 << endl;   
                break;
            
            case 5:
                //6 -Calcular a quantidade de componentes fortemente conexas em um grafo orientado.
                if (tipoGrafo == "direcionado")
                {
                    qtdCompConex = compConexo(lista_adj, qtdVertices);
                    cout << qtdCompConex << endl;
                }else cout << -1 << endl;                            
                break;
            
            case 6:
                //7 -Imprimir os vértices de articulação de um grafo não-orientado (priorizar a ordem lexicográfica dos vértices).    
                cout<<"7- ";
                qtdArticulado = articulados(lista_adj, qtdVertices);
                if (tipoGrafo != "direcionado")
                {
                    if (!qtdArticulado.empty())
                    {
                    for (int vertices : qtdArticulado)
                    {
                        cout << vertices << " ";
                    }
                    cout << endl;
                    }else cout << 0 << endl;
                }else cout << -1 << endl;   
                
                break;
                
            case 7:            
                //8 -Calcular quantas arestas ponte possui um grafo não-orientado.  
                if (tipoGrafo != "direcionado")
                {
                    cout <<"8- ";
                    qtdPontes = pontes(lista_adj);  
                    cout << qtdPontes << endl;
                }else cout << -1 << endl;   
                
                break;

            case 8:
                //9 -Imprimir a árvore em profundidade (priorizando a ordem lexicográfica dos vértices; 0 é a origem). Você deve imprimir o identificador das arestas. Caso o grafo seja desconexo, considere apenas a árvore com a raíz 0.   
                arestasDfs = dfs(lista_adj, qtdVertices);
                cout<<"9- ";
                for(int id : arestasDfs) {
                    cout << id << " ";
                }
                cout<<endl;
                break;

            case 9:
                //10 -Árvore de largura (priorizando a ordem lexicográfica dos vértices; 0 é a origem). Você deve imprimir o identificador das arestas. Caso o grafo seja desconexo, considere apenas a árvore com a raíz 0.    
                arestasBfs = bfs(lista_adj, qtdVertices);
                cout<<"10- ";
                for(int id : arestasBfs) {
                    cout << id << " ";
                }
                cout<<endl;
                break;

            case 10:
                //11 -Calcular o valor final de uma árvore geradora mínima (para grafos não-orientados).
                if(!conexoNaoDir(lista_adj, qtdVertices) or tipoGrafo == "direcionado")cout << "11- -1" << endl;
                else{
                    int pesoTotal = 0;
                    prim(lista_adj, qtdVertices, pesoTotal);
                    cout << "11- " << pesoTotal << endl; 
                }    
                break;
            
            case 11:
                //12 -Imprimir a ordem os vértices em uma ordenação topológica. Esta função não fica disponível em grafos não direcionado. Deve-se priorizar a ordem lexicográfica dos vértices.   
                if (tipoGrafo == "nao_direcionado")
                {
                    cout << -1 << endl;
                }else{
                    vector<int> top = ordenacao_topologica(lista_adj,qtdVertices);
                    cout<<"12- ";
                    for(int id : top) {
                        cout << id << " ";
                    }
                    cout<<endl;
                }
                break;

            case 12:
                //13 -Valor do caminho mínimo entre dois vértices (para grafos não-orientados com pelo menos um peso diferente nas arestas).  0 é a origem; n-1 é o destino.   
                if(!conexoNaoDir(lista_adj, qtdVertices) or tipoGrafo == "direcionado")cout << "13- -1" << endl;
                else{  
                    int caminhoMin = djikstra(lista_adj, qtdVertices);
                    cout << "13- " << caminhoMin << endl; 
                }   
                break;

            case 13: 
                //14 -Valor do fluxo máximo para grafos direcionados. 0 é a origem; n-1 é o destino.   
                cout << "13 buceta" << endl;
                break;

            case 14:
                //15 -Fecho transitivo para grafos direcionados.  Deve-se priorizar a ordem lexicográfica dos vértices; 0 é o vértice escolhido.
                if (tipoGrafo == "direcionado")
                {
                    fecho = fechoTrans(lista_adj, qtdVertices);
                    for (int i = 0; i < fecho.size(); i++)
                    {
                        cout << fecho[i] << " ";
                    }
                    cout << endl;
                }else cout << -1 << endl;   
                break;
        }
    }
    return 0;
}