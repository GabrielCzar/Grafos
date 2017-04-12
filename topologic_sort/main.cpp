#include <iostream>
/*
Ordenação Topológica.

Exercício:
Execute o algoritmo de ordenação topológica baseado em DFS. Para o grafo proposto como exemplo.

void inicializa_grafo(list<int> Adj[]){
   Adj[A].push_back(C);
   Adj[B].push_back(C);
   Adj[C].push_back(D);
   Adj[C].push_back(E);
   Adj[D].push_back(F);
   Adj[E].push_back(F);
   Adj[F].push_back(G);
   Adj[F].push_back(H);
}

Qual ordem topológica é encontrada pelo algoritmo?
Este grafo possui só uma ordenação topológica? Se não, mostre outro exemplo.
Quais são as fontes e sorvedouros do grafo?

*/
#include <list>
#define N 8

using namespace std;

enum Cor {branco, cinza, preto};
enum Vertices {A, B, C, D, E, F, G, H};

list<int> ord_topologica;
list<int> Adj[N];
int cor[N];
int d[N];
int f[N];
int pi[N];
int tempo = 0;

bool  topologic_sort_visit (int u) {
    cor[u] = cinza;
    d[u] = tempo;
    tempo = tempo + 1;

    for (list<int>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++) {
        if (cor[*it] == branco) {
            pi[*it] = u;
            topologic_sort_visit (*it);
        } if (cor[*it] == cinza)
            return false;
    }

    cor[u] = preto;
    f[u] = tempo;
    tempo = tempo + 1;
    ord_topologica.push_front(u);
    return true;
}

bool topologic_sort () {
    for (int i = 0; i < N; i++) {
        cor[i] = branco;
        pi[i] = -1;
    }
    tempo = 0;
    for (int i = 0; i < N; i++)
        if (cor[i] == branco)
            if (!topologic_sort_visit(i))
                return false;
    return true;
}

void inicializa_grafo(){
   Adj[A].push_back(C); // 0 2
   Adj[B].push_back(C); // 1 2
   Adj[C].push_back(D); // 2 3
   Adj[C].push_back(E); // 2 4
   Adj[D].push_back(F); // 3 5
   Adj[E].push_back(F); // 4 5
   Adj[F].push_back(G); // 5 6
   Adj[F].push_back(H); // 5 7
}

int main(){
    inicializa_grafo();
    topologic_sort();
    for (auto value : ord_topologica)
        cout << value << " ";

    // Fontes(entrando):  A e B
    // Sorvedouros(saindo): G e H
    return 0;
}
