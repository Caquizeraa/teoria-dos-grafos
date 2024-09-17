#include <iostream>
#include <vector>
#include "../include/grafo.h"

using namespace std;

class Menu{
    private:
        int option; // Opcao do menu
        // Dados do grafo inserido
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
        // Destrutor
        void destrutorMenu();
};

// Construtor
Menu::Menu(){
    menuInicial();
}

// Metodos Gerais
void Menu::barraSuperior(){ // Limpa a tela e imprime a barra superior
    system("cls"); 
    cout << "----------------|Teoria dos Grafos|----------------" << endl;
}

// Metodos Menu Inicial (inserção)
void Menu::menuInicial(){
    // Imprime menu inicial
    this->barraSuperior();
    cout<<"Iniciando insercao do grafo!"<< endl;
    cout << "Escolha o tipo do grafo:" << endl;
    cout << "1 - Direcionado" << endl;
    cout << "2 - Nao Direcionado" << endl;
    // Recebe entrada do usuario ate que seja 1 (direcionado) ou 2 (nao direcionado)
    do{
        cin>>this->option;
        if(this->option!=1 and this->option!=2){
            cout<<"Opcao invalida! Digite uma opcao valida."<< endl;
        }
    }
    while(option != 1 and option !=2);
    // Transformo a escolha em booleano (0 - Direcionado | 1 - Nao direcionado)
    if(option == 1){
        this->tipoGrafo = 0;
    }else{
        this->tipoGrafo = 1;
    }
    // Chamo o menu que coleta tamanho do grafo
    this->coletaTamanho();
}

void Menu::coletaTamanho(){
    this->barraSuperior();
    // Recebe entrada do usuario ate que seja um valor maior que 0, que se torna o numero de vertices
    cout << "Digite a quantidade de vertices: ";
    do{
        cin >> this->qtdVertices;
        if(this->qtdVertices <= 0){
            cout<<"Quantidade invalida! Digite novamente!"<< endl;
        }
    }while(this->qtdVertices <= 0);
    
    // Recebe entrada do usuario ate que seja um valor maior ou igual 0, que se torna o numero de arestas
    cout << "Digite a quantidade de arestas: ";
    do{
        cin >> this->qtdArestas;
        if(this->qtdArestas < 0){
            cout<<"Quantidade invalida! Digite novamente!"<< endl;
        }
    }while(this->qtdArestas < 0);
    // Chama o menu que permite que o usuario confirme as informacoes ja inseridas
    this->confereGrafo();
}

void Menu::confereGrafo(){
    this->barraSuperior();
    // Escreve as propriedades atuais do grafo (tipo do grafo, quantidade de vertices e de arestas)
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
    // Recebe entrada do usuario ate que seja 1 (prosseguir) ou 2 (reinserir essas informacoes)
    do{
        cin>>this->option;
        if(this->option!=1 and this->option!=2){
            cout<<"Opcao invalida! Digite uma opcao valida."<< endl;
        }
    }
    while(option != 1 and option !=2);

    // Se prosseguir, chama o menu que recebe as arestas, se não volta do começo
    if(option == 1){
        this->coletaArestas();
    }else{
        this->menuInicial();
    }
}

void Menu::coletaArestas(){
    this->barraSuperior();
    // Inicializo a lista de arestas
    vector<vector<pair<int, pair<int, int>>>> listaAdj(qtdVertices);
    cout<<"Insira todas as arestas conforme o modelo a seguir:"<<endl;
    cout<<"(ID Origem Destino Peso)"<<endl;
    // Recebo entradas de cada aresta (ID, ORIGEM, DESTINO, PESO)
    for(int i = 0; i < qtdArestas; i++){
        int id, origem, destino, peso;
        cin >> id >> origem >> destino >> peso;
        // Adiciono a aresta na lista de adjacencia da origem
        listaAdj[origem].push_back(make_pair(id, make_pair(destino, peso)));
        if(this->tipoGrafo == 1){ // Se o grafo for não direcionado
            // Adiciono a mesma aresta, na lista de adjacencia do destino
            listaAdj[destino].push_back(make_pair(id, make_pair(origem, peso)));
        }
    }
    // Instancio um objeto da classe grafo, que sera o grafo trabalhado
    this->grafo = new Grafo(this->qtdVertices, this->qtdArestas, listaAdj, this->tipoGrafo);
    // Chamo o menu de conferencia do grafo
    this->confereFinal();
}

void Menu::confereFinal(){
    this->barraSuperior();
    // Escreve as propriedades atuais do grafo (tipo do grafo, quantidade de vertices e de arestas)
    this->imprimeGrafo();
    // Recebe entrada do usuario ate que seja 1 (prosseguir) ou 2 (reinserir o grafo)
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
    // Se prosseguir, chama o menu que tem as funcionalidade do programa, se não volta do começo
    if(option == 1){
        this->menuOpcoes();
    }else{
        this->menuInicial();
    }
}

// Metodos Menu Opções
void Menu::menuOpcoes(){
    this->barraSuperior();
    // Menu com as 3 funcionalidades do programa
    cout<<"Escolha uma opcao"<<endl;
    cout<<"1 - Opcoes do Grafo"<<endl;
    cout<<"2 - Imprimir o Grafo"<<endl;
    cout<<"3 - Inserir Novo Grafo"<<endl;
    cout<<"4 - Encerrar"<<endl;
    // Recebe entrada do usuario, ate que seja um valor de 1 a 4, e faz algo
    do{
        cin>>this->option;
        switch (this->option){
            // Se entrada for 1, chama o menu de opcoes do grafo
            case 1:
                this->menuOpcoesGrafo();
                break;
            // Se entrada for 2, chama o menu que imprime o grafo
            case 2:
                this->subMenu(&Menu::imprimeGrafo);
                break;
            // Se entrada for 3, chama o menu inicial, pedindo a insercao de um novo grafo
            case 3:
                this->menuInicial();
                break;
            // Se entrada for 4, não faz nada, e a execucao termina naturalmente
            case 4:
                this->destrutorMenu();
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
    // Chama uma funcao que imprime as opcoes e recebe entradas do usuario (sensivel ao tipo do grafo)
    if(!this->tipoGrafo){
        this->opcoesDirecionado();
    }
    else{
        this->opcoesNaoDirecionado();
    }
}

void Menu::opcoesDirecionado(){
    // Mostra as opcoes para grafos direcionados
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
    // Recebe entrada do usuario, ate que seja um valor de 1 a 10
    do{
        cin>>this->option;
        // Chama um menu diferente, com base na opcao escolhida
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
     // Mostra as opcoes para grafos nao direcionados
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
    // Recebe entrada do usuario, ate que seja um valor de 1 a 12
    do{
        cin>>this->option;
        // Chama um menu diferente, com base na opcao escolhida
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
    // Escreve as propriedades atuais do grafo (tipo do grafo, quantidade de vertices e de arestas)
    cout << "Informacoes do grafo escolhido!"<<endl<<endl;
    cout << "Tipo: ";
    if(this->tipoGrafo==0){
        cout<<"Direcionado"<<endl;
    }else{
        cout<<"Nao Direcionado"<<endl;
    }
    cout<<"Quantidade de vertices: "<<this->qtdVertices<<endl;
    cout<<"Quantidade de arestas: "<<this->qtdArestas<<endl<<endl;
    // Escreve cada vertice, com suas arestas
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
    // Submenu que é usado em todas as opcoes
    this->barraSuperior(); // Chama funcao que imprime a barra superior
    (this->*subMenuFunc)(); // Chama uma funcao (funcoes das opcoes) passada por parametro
    cout<<endl;
    // Recebe entrada do usuario ate que seja 1 (voltar ao menu de opcoes gerais) ou 2 (encerrar a execucao do programa) 
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
    // Se entrada for 1, voltar do inicio, se for 2, encerrar a execucao
    if(option == 1){
        this->menuOpcoes();
    }else{
        this->destrutorMenu();
    }
}

// Submenus Opcoes - Gerais
void Menu::eureliano(){ // Menu que mostra o resultado da funcao eureliano
    bool eureliano = grafo->getEureliano();
    if(eureliano){
        cout<<"O grafo e eureliano";
    }else{
        cout<<"O grafo nao e eureliano";
    }
}
void Menu::ciclo(){ // Menu que mostra o resultado da funcao ciclo
    bool ciclo = grafo->getCiclo();
    if(ciclo){
        cout<<"O grafo possui ciclo!"<<endl;
    }else{
        cout<<"O grafo nao possui ciclo!"<<endl;
    }
}
void Menu::dfs(){ // Menu que mostra o resultado da funcao dfs
    vector<int> dfsArestas = grafo->getDfsArestas();
    cout<<"O ID das arestas da arvore de profundidade e: ";
    for(auto& aresta : dfsArestas){
        cout<<aresta<<" ";
    }
    cout<<endl;
}
void Menu::bfs(){ // Menu que mostra o resultado da funcao bfs
    vector<int> bfsArestas = grafo->getBfsArestas();
    cout<<"O ID das arestas da arvore de largura e: ";
    for(auto aresta : bfsArestas){
        cout<<aresta<<" ";
    }
    cout<<endl;
}

// Submenus Opcoes - Direcionados
void Menu::fracamenteConexo(){ // Menu que mostra o resultado da funcao conexo para grafos direcionados (fracamente)
    bool fracamenteConexo = grafo->getConexo();
    if(fracamenteConexo){
        cout<<"O grafo e fracamente conexo!"<<endl;
    }else{
        cout<<"O grafo nao e fracamente conexo!"<<endl;
    }
}

void Menu::compFortementeConexas(){
    int compConexa = grafo->getCompConexa();
    if(compConexa <= 1){
        cout<<"O grafo tem "<<compConexa<< " componente conexa!";
    }else{
        cout<<"O grafo tem "<<compConexa<< " componentes conexas!";
    }
    cout<<endl;
}

void Menu::ordemTopologica(){
    vector<int> ordemTopologica = grafo->getOrdemTopologica();
    cout<<"O ID dos vertices ordenados topologicamente e: ";
    for(auto vertice : ordemTopologica){
        cout<<vertice<<" ";
    }
    cout<<endl;
}
void Menu::fluxoMaximo(){

}
void Menu::fechoTransitivo(){

}

// Submenus Opcoes - Nao Direcionados
void Menu::conexo(){ // Menu que mostra o resultado da funcao conexo para grafos nao direcionados
    bool conexo = grafo->getConexo();
    if(conexo){
        cout<<"O grafo e conexo!"<<endl;
    }else{
        cout<<"O grafo nao e conexo!"<<endl;
    }
}
void Menu::bipartido(){

}
void Menu::compConexas(){
    int compConexa = grafo->getCompConexa();
    if(compConexa <= 1){
        cout<<"O grafo tem "<<compConexa<< " componente conexa!";
    }else{
        cout<<"O grafo tem "<<compConexa<< " componentes conexas!";
    }
    cout<<endl;
}
void Menu::verticesArticulacao(){

}
void Menu::arestasPonte(){

}
void Menu::agm(){

}
void Menu::caminhoMinimo(){

}

// Metodo destrutor - Acionado no fim da execucao, para garantir consistencia da memoria
void Menu::destrutorMenu(){
    delete[] this->grafo;
    this->grafo = nullptr;
}
