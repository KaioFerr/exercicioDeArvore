//Bibliotecas necessárias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinariaBusca.h"
#include <queue>

using namespace std;

TipoCelula *Raiz;

int Contador;

void ArvoreBinariaBusca_Construtor()
{

    Raiz = NULL;
    Contador = 0;
}

void ArvoreBinariaBusca_Destrutor(){


     ArvoreBinariaBusca_Destrutor(Raiz);
     Contador = 0;
}

void ArvoreBinariaBusca_Destrutor(TipoCelula *&Raiz){


     if(Raiz!=NULL)
     {
         ArvoreBinariaBusca_Destrutor(Raiz->Esq);
         ArvoreBinariaBusca_Destrutor(Raiz->Dir);

         delete(Raiz);
         Raiz = NULL;
     }
}

bool ArvoreBinariaBusca_Vazia()
{

   return Raiz == NULL;
}

int ArvoreBinariaBusca_Tamanho()
{

   return Contador;
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento)
{

     return ArvoreBinariaBusca_Inserir(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Inserir(TipoDado Elemento, TipoCelula *&Raiz)
{

     if(Raiz == NULL)
     {
        if((Raiz = new(TipoCelula)) == NULL)
           return false;
        else
        {
            Raiz->Item = Elemento;
            Raiz->Esq = Raiz->Dir = NULL;
            Contador++;
            return true;
        }
     }
     else
     {
         if(Elemento < Raiz->Item)
           return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Item)
              return ArvoreBinariaBusca_Inserir(Elemento, Raiz->Dir);
            else return false;
         }
     }
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento)
{

     return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz);
}

bool ArvoreBinariaBusca_Pesquisar(TipoDado Elemento, TipoCelula *Raiz)
{

     if(Raiz == NULL) return false;
     else
     {
         if(Elemento < Raiz->Item)
           return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Item)
              return ArvoreBinariaBusca_Pesquisar(Elemento, Raiz->Dir);
            else return true;
         }
     }
}

void ArvoreBinariaBusca_Percurso(int modo)
{

     switch (modo)
     {
        case 1: ArvoreBinariaBusca_PreOrdem(Raiz); break;
        case 2: ArvoreBinariaBusca_EmOrdem(Raiz); break;
        case 3: ArvoreBinariaBusca_PosOrdem(Raiz); break;
        default: cout <<"Ordem desconhecida";
     }
     cout << endl << endl;
     system("pause");
}

void ArvoreBinariaBusca_EmOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         ArvoreBinariaBusca_EmOrdem(Raiz->Esq);
         cout << Raiz->Item << " ";
         ArvoreBinariaBusca_EmOrdem(Raiz->Dir);
     }
}

void ArvoreBinariaBusca_PreOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         cout << Raiz->Item << " ";
         ArvoreBinariaBusca_PreOrdem(Raiz->Esq);
         ArvoreBinariaBusca_PreOrdem(Raiz->Dir);
     }
}

void ArvoreBinariaBusca_PosOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         ArvoreBinariaBusca_PosOrdem(Raiz->Esq);
         ArvoreBinariaBusca_PosOrdem(Raiz->Dir);
         cout << Raiz->Item << " ";
     }
}

void ArvoreBinariaBusca_Imprimir_Por_Nivel(int nivel) {
    if (Raiz == NULL) {
        cout << "A árvore está vazia." << endl;
        return;
    }

    // Cria uma fila para armazenar os nós e seus níveis
    queue<pair<TipoCelula*, int>> fila;
    fila.push(make_pair(Raiz, 0)); // Insere a raiz na fila com nível 0

    while (!fila.empty()) {
        auto nodo = fila.front(); // Pega o nó da frente da fila
        fila.pop();

        TipoCelula* atual = nodo.first; // O nó atual
        int nivel_atual = nodo.second; // O nível atual

        // Se o nível atual for igual ao nível desejado, imprime o item
        if (nivel_atual == nivel) {
            cout << atual->Item << " ";
        }

        // Adiciona os filhos à fila, se existirem
        if (atual->Esq != NULL) {
            fila.push(make_pair(atual->Esq, nivel_atual + 1));
        }
        if (atual->Dir != NULL) {
            fila.push(make_pair(atual->Dir, nivel_atual + 1));
        }
    }

    cout << endl; // Finaliza a linha após imprimir todos os nós do nível
}