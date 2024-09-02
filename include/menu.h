#ifndef MENU_H
#define MENU_H

#include "./grafo.h"

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
        void subMenu(void (*subMenuFunc)());
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

#endif
