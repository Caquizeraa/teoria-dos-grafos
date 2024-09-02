#include <iostream>
#include <vector>
#include "../include/grafo.h"

using namespace std;

class Menu{
    private:
        int option;
        bool tipoGrafo; // Direcionado - 0 | Nao Direcionado - 1
        int qtdVertices;
        int qtdArestas;
        Grafo* grafo;
    public:
        // Construtor
        Menu();
        // Metodos Menu Inicial (inserção)
        void menuInicial();
        void coletaTamanho();
        void confereGrafo();
        void coletaArestas();
        void confereFinal();
        // Metodos Gerais
        void barraSuperior();
        // Metodos Menu Opcoes
        void menuOpcoes();
        void menuOpcoesGrafo();
        void opcoesDirecionado();
        void opcoesNaoDirecionado();
        void imprimeGrafo();
        // Submenus Opcoes
        void subMenu(void (Menu::*subMenuFunc)());
        // Submenus Opcoes - Gerais
        void eureliano();
        void ciclo();
        void dfs();
        void bfs();
        // Submenus Opcoes - Direcionados
        void fracamenteConexo();
        void compFortementeConexas();
        void ordemTopologica();
        void fluxoMaximo();
        void fechoTransitivo();
        // Submenus Opcoes - Nao Direcionados
        void conexo();
        void bipartido();
        void compConexas();
        void verticesArticulacao();
        void arestasPonte();
        void agm();
        void caminhoMinimo();
};

// Construtor
Menu::Menu(){
    menuInicial();
}

// Metodos Gerais
void Menu::barraSuperior(){
    system("cls"); 
    cout << "----------------|Teoria dos Grafos|----------------" << endl;
}

// Metodos Menu Inicial (inserção)
void Menu::menuInicial(){
    this->barraSuperior();
    cout<<"Iniciando insercao do grafo!"<< endl;
    cout << "Escolha o tipo do grafo:" << endl;
    cout << "1 - Direcionado" << endl;
    cout << "2 - Nao Direcionado" << endl;
    do{
        cin>>this->option;
        if(this->option!=1 and this->option!=2){
            cout<<"Opcao invalida! Digite uma opcao valida."<< endl;
        }
    }
    while(option != 1 and option !=2);
    if(option == 1){
        this->tipoGrafo = 0;
    }else{
        this->tipoGrafo = 1;
    }
    this->coletaTamanho();
}

void Menu::coletaTamanho(){
    this->barraSuperior();
    cout << "Digite a quantidade de vertices: ";
    do{
        cin >> this->qtdVertices;
        if(this->qtdVertices <= 0){
            cout<<"Quantidade invalida! Digite novamente!"<< endl;
        }
    }while(this->qtdVertices <= 0);

    cout << "Digite a quantidade de arestas: ";
    do{
        cin >> this->qtdArestas;
        if(this->qtdArestas < 0){
            cout<<"Quantidade invalida! Digite novamente!"<< endl;
        }
    }while(this->qtdArestas < 0);
    this->confereGrafo();
}

void Menu::confereGrafo(){
    this->barraSuperior();
    cout << "Informacoes do grafo escolhido!"<<endl<<endl;
    cout << "Tipo: ";
    if(this->tipoGrafo==0){
        cout<<"Direcionado"<<endl;
    }else{
        cout<<"Nao Direcionado"<<endl;
    }
    cout<<"Quantidade de vertices: "<<this->qtdVertices<<endl;
    cout<<"Quantidade de arestas: "<<this->qtdArestas<<endl<<endl;
    cout<<"Deseja continuar ou alterar as propriedades?"<<endl;
    cout << "1 - Continuar" << endl;
    cout << "2 - Alterar" << endl;
    do{
        cin>>this->option;
        if(this->option!=1 and this->option!=2){
            cout<<"Opcao invalida! Digite uma opcao valida."<< endl;
        }
    }
    while(option != 1 and option !=2);

    if(option == 1){
        this->coletaArestas();
    }else{
        this->menuInicial();
    }
}

void Menu::coletaArestas(){
    this->barraSuperior();
    vector<vector<pair<int, pair<int, int>>>> listaAdj(qtdVertices);
    cout<<"Insira todas as arestas conforme o modelo a seguir:"<<endl;
    cout<<"(ID Origem Destino Peso)"<<endl;
    for(int i = 0; i < qtdArestas; i++){
        int id, origem, destino, peso;
        cin >> id >> origem >> destino >> peso;
        listaAdj[origem].push_back(make_pair(id, make_pair(destino, peso)));
        if(this->tipoGrafo == 1){
            listaAdj[destino].push_back(make_pair(id, make_pair(origem, peso)));
        }
    }
    this->grafo = new Grafo(this->qtdVertices, this->qtdArestas, listaAdj, this->tipoGrafo);
    this->confereFinal();
}

void Menu::confereFinal(){
    this->barraSuperior();
    cout << "Informacoes do grafo escolhido!"<<endl<<endl;
    cout << "Tipo: ";
    if(this->tipoGrafo==0){
        cout<<"Direcionado"<<endl;
    }else{
        cout<<"Nao Direcionado"<<endl;
    }
    
    cout<<"Quantidade de vertices: "<<this->qtdVertices<<endl;
    cout<<"Quantidade de arestas: "<<this->qtdArestas<<endl<<endl;
    cout<<"Arestas de cada vertice: "<<endl;
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->grafo->getLista();
    for(int i = 0; i<qtdVertices; i++){
        cout<<"Vertice "<<i<<":"<<endl;
        for(auto aresta: listaAdj[i]){
            int id = aresta.first;
            int destino = aresta.second.first;
            int peso = aresta.second.second;
            cout<<"     Destino: " << destino << " Peso: "<< peso <<" ID: "<< id << endl;
        }
    }
    cout<<endl;
    cout<<"Deseja continuar ou alterar o grafo?"<<endl;
    cout << "1 - Continuar" << endl;
    cout << "2 - Alterar" << endl;
    do{
        cin>>this->option;
        if(this->option!=1 and this->option!=2){
            cout<<"Opcao invalida! Digite uma opcao valida."<< endl;
        }
    }
    while(option != 1 and option !=2);

    if(option == 1){
        this->menuOpcoes();
    }else{
        this->menuInicial();
    }
}

// Metodos Menu Opções
void Menu::menuOpcoes(){
    this->barraSuperior();
    cout<<"Escolha uma opcao"<<endl;
    cout<<"1 - Opcoes do Grafo"<<endl;
    cout<<"2 - Imprimir o Grafo"<<endl;
    cout<<"3 - Inserir Novo Grafo"<<endl;
    cout<<"4 - Encerrar"<<endl;
    do{
        cin>>this->option;
        switch (this->option){
            case 1:
                this->menuOpcoesGrafo();
                break;
            case 2:
                this->subMenu(&Menu::imprimeGrafo);
                break;
            case 3:
                this->menuInicial();
                break;
            case 4:
                // Não faz nada, e a execucao termina naturalmente
                break;
            default:
                cout<<"Opcao invalida! Digite uma opcao valida."<< endl;
                break; 
        }
    }while(this->option<1 or this->option>4);
}

void Menu::menuOpcoesGrafo(){
    this->barraSuperior();
    cout<<"Escolha uma opcao"<<endl;
    // Opcoes para grafos direcionados
    if(!tipoGrafo){
        this->opcoesDirecionado();
    }
    // Opcoes para grafos nao direcionados
    else{
        this->opcoesNaoDirecionado();
    }
}

void Menu::opcoesDirecionado(){
    cout<<"Opcoes para seu grafo direcionado: "<< endl;
    cout<<"1 -  Fracamente Conexo?"<<endl;
    cout<<"2 -  Eureliano?"<<endl;
    cout<<"3 -  Possui Ciclo?"<<endl;
    cout<<"4 -  Quantidade de Componentes Fortemente Conexas"<<endl;
    cout<<"5 -  Arvore de Profundidade (DFS)"<<endl;
    cout<<"6 -  Arvore de Largura (BFS)"<<endl;
    cout<<"7 -  Ordem Topologica"<<endl;
    cout<<"8 -  Fluxo Maximo"<<endl;
    cout<<"9 -  Fecho Transitivo"<<endl;
    cout<<"10 - Voltar"<< endl;
    do{
        cin>>this->option;
        switch (this->option){
            case 1:
                this->subMenu(&Menu::fracamenteConexo);
                break;
            case 2:
                this->subMenu(&Menu::eureliano);
                break;
            case 3:
                this->subMenu(&Menu::ciclo);
                break;
            case 4:
                this->subMenu(&Menu::compFortementeConexas);
                break;
            case 5:
                this->subMenu(&Menu::dfs);
                break;
            case 6:
                this->subMenu(&Menu::bfs);
                break;
            case 7:
                this->subMenu(&Menu::ordemTopologica);
                break;
            case 8:
                this->subMenu(&Menu::fluxoMaximo);
                break;
            case 9:
                this->subMenu(&Menu::fechoTransitivo);
                break;
            case 10:
                this->menuOpcoes();
                break;
            default:
                cout<<"Opcao invalida! Digite uma opcao valida."<< endl;
                break;  
        }
    }while(this->option<1 or this->option>9);
}

void Menu::opcoesNaoDirecionado(){
    cout<<"Opcoes para seu grafo nao direcionado: "<< endl;
    cout<<"1 -  Conexo?"<<endl;
    cout<<"2 -  Bipartido?"<<endl;
    cout<<"3 -  Eureliano?"<<endl;
    cout<<"4 -  Possui Ciclo?"<<endl;
    cout<<"5 -  Quantidade de Componentes Conexas"<<endl;
    cout<<"6 -  Vertices de Articulacao"<<endl;
    cout<<"7 -  Quantidade de Arestas Ponte"<<endl;
    cout<<"8 -  Arvore de Profundidade (DFS)"<<endl;
    cout<<"9 -  Arvore de Largura (BFS)"<<endl;
    cout<<"10 - Arvore Geradora Minima"<<endl;
    cout<<"11 - Valor do Caminho Minimo"<<endl;
    cout<<"12 - Voltar"<< endl;
    do{
        cin>>this->option;
        switch (this->option){
            case 1:
                this->subMenu(&Menu::conexo);
                break;
            case 2:
                this->subMenu(&Menu::bipartido);
                break;
            case 3:
                this->subMenu(&Menu::eureliano);
                break;
            case 4:
                this->subMenu(&Menu::ciclo);
                break;
            case 5:
                this->subMenu(&Menu::compConexas);
                break;
            case 6:
                this->subMenu(&Menu::verticesArticulacao);
                break;
            case 7:
                this->subMenu(&Menu::arestasPonte);
                break;
            case 8:
                this->subMenu(&Menu::dfs);
                break;
            case 9:
                this->subMenu(&Menu::bfs);
                break;
            case 10:
                this->subMenu(&Menu::agm);
                break;
            case 11:
                this->subMenu(&Menu::caminhoMinimo);
                break;
            case 12:
                this->menuOpcoes();
                break;
            default:
                cout<<"Opcao invalida! Digite uma opcao valida."<< endl;
                break;  
        }
    }while(this->option<1 or this->option>9);
}

void Menu::imprimeGrafo(){
    cout << "Informacoes do grafo escolhido!"<<endl<<endl;
    cout << "Tipo: ";
    if(this->tipoGrafo==0){
        cout<<"Direcionado"<<endl;
    }else{
        cout<<"Nao Direcionado"<<endl;
    }
    cout<<"Quantidade de vertices: "<<this->qtdVertices<<endl;
    cout<<"Quantidade de arestas: "<<this->qtdArestas<<endl<<endl;
    cout<<"Arestas de cada vertice: "<<endl;
    vector<vector<pair<int, pair<int, int>>>> listaAdj = this->grafo->getLista();
    for(int i = 0; i<qtdVertices; i++){
        cout<<"Vertice "<<i<<":"<<endl;
        for(auto aresta: listaAdj[i]){
            int id = aresta.first;
            int destino = aresta.second.first;
            int peso = aresta.second.second;
            cout<<"     Destino: " << destino << " Peso: "<< peso <<" ID: "<< id << endl;
        }
    }
}

// Submenus Opcoes
void Menu::subMenu(void (Menu::*subMenuFunc)()){
    this->barraSuperior();
    (this->*subMenuFunc)();
    cout<<endl;
    cout<<"Deseja voltar ou encerrar a execucao?"<<endl;
    cout << "1 - Voltar" << endl;
    cout << "2 - Encerrar" << endl;
    do{
        cin>>this->option;
        if(this->option!=1 and this->option!=2){
            cout<<"Opcao invalida! Digite uma opcao valida."<< endl;
        }
    }
    while(option != 1 and option !=2);

    if(option == 1){
        this->menuOpcoes();
    }
}

// Submenus Opcoes - Gerais
void Menu::eureliano(){
    cout<<"O grafo e eureliano";
}
void Menu::ciclo(){
    cout<<"O grafo possui ciclos";
}
void Menu::dfs(){
    vector<int> dfsArestas = grafo->getDfsArestas();
    cout<<"O ID das arestas da arvore de profundidade e: ";
    for(auto aresta : dfsArestas){
        cout<<aresta<<" ";
    }
    cout<<endl;
}
void Menu::bfs(){

}

// Submenus Opcoes - Direcionados
void Menu::fracamenteConexo(){

}

void Menu::compFortementeConexas(){

}

void Menu::ordemTopologica(){

}
void Menu::fluxoMaximo(){

}
void Menu::fechoTransitivo(){

}

// Submenus Opcoes - Nao Direcionados
void Menu::conexo(){

}
void Menu::bipartido(){

}
void Menu::compConexas(){

}
void Menu::verticesArticulacao(){

}
void Menu::arestasPonte(){

}
void Menu::agm(){

}
void Menu::caminhoMinimo(){

}
