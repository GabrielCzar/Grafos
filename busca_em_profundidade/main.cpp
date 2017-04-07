/*
BFS(G, s): // busca em largura
   // INICIALIZAÇÃO                                       // Lista       // Matriz
  para cada vértice u de G (excluindo o s)               // O(v)
     cor[u] <- branco; d[u] <- oo; pi[u] <- NULO         // O(v)
  cor[s] <- cinza; d[s] <- 0; pi[s] <- NULO              // O(1)

  declare uma fila vazia Q                               // O(1)
  insira s na fila Q                                     // O(1)
  enquanto Q não é vazia                                 // O(v)
     remova o próximo elem. da fila Q e o armazene em u  // O(v)
     para cada vértice v em Adj[u]                       // O(v + e)    // O(v²)
        se cor[v] = branco                               // O(e)        //
          cor[v] <- cinza; d[v] <- d[u] + 1; pi[v] <- u // O(e)        //
          insira v na fila Q                            // O(e)        //
    cor[u] <- preto                                     // O(v)        //
*/

#include <iostream>
#include <list>
#include <queue>

#define N 8

using namespace std;

enum Vertices {s,t,u,v,x,y,w,z};
             //0 1 2 3 4 5 6 7

enum enum_cor { branco, preto, cinza };

list<int> Adj[N];

int cor[N]; //Cor
int d[N]; // distancia
int pi[N]; //predecessor
int tempo = 0;
int f[N]; //tempo de fim

void dfs_visit (int u) {
   cor[u] = cinza;
   d[u] = tempo;
   tempo = (tempo + 1);
   for (list<int>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++) {
        if (cor[*it] == branco){
            pi[*it] = u;
            dfs_visit(*it);
        }
   }
   cor[u] = preto;
   f[u] = tempo;
   tempo = (tempo + 1);
}

void dfs () {
    for (int i = 0; i < N; i++) {
        cor[i] = branco; pi[i] = -1;
    }
    tempo = 1;
    for (int i = 0; i < N; i++)
        if (cor[i] == branco)
            dfs_visit(i);
}

void inicializa_grafo(){
   Adj[s].push_back(z);
   Adj[s].push_back(w);
   Adj[z].push_back(y);
   Adj[z].push_back(w);
   Adj[y].push_back(x);
   Adj[x].push_back(z);
   Adj[w].push_back(x);
   Adj[t].push_back(v);
   Adj[t].push_back(u);
   Adj[v].push_back(w);
   Adj[v].push_back(s);
   Adj[u].push_back(v);
   Adj[u].push_back(t);
}

int main () {
    inicializa_grafo();
    dfs();

    for (int i = 0; i < N; i++)
        cout << "Vertice: " << i
             << "\tTempo-Inicial: " << d[i]
             << "\tTempo-Final: "   << f[i]
             << "\tPredecesor: "    << pi[i] << endl;

    return 0;
}
