#include <iostream>
#include <list>
#include <queue>

#define N 9
#define DENSIDADE 0.1

using namespace std;

enum enum_cor { branco, preto, cinza };
enum Conjunto {_, A, B};

list<int> Adj[N];
int cor[N]; //Cor
int d[N]; // distancia
int pi[N]; //predecessor
int tempo = 0;
int f[N]; //tempo de fim
int conj[N];

void imprime (int u, int v) {
    cout << v << " ";
    int i = u;
    while (i != v) {
        cout << i << " ";
        i = pi[i];
    }
}

bool dfs_visit_bipartido(int u) {
    cor[u] = cinza;
    for (list<int>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++) {
        if (cor[*it] == branco){
            pi[*it] = u;
            conj[*it] = (conj[u] == A) ? B : A;
            return dfs_visit_bipartido(*it);
        } else if (conj[*it] == conj[u]){
            imprime(u, *it);
            return false;
        }
    }
    return true;
}

bool dfs_bipartido () {
    for (int i = 0; i < N; i++) {
        cor[i] = branco;
        pi[i] = -1;
    }
    for (int i = 0; i < N; i++){
        if (cor[i] == branco){
            conj[i] = A;
            if (!dfs_visit_bipartido(i))
                return false;
        }
    }
    return true;
}

void inicializa_grafo()
{
   enum Vertices {cueca, meia, calca, sapato, relogio, cinto, camisa, gravata, paleto};
                //    0     1      2       3        4      5       6        7       8
   Adj[cueca].push_back(calca);
   Adj[cueca].push_back(sapato);
   Adj[meia].push_back(sapato);
   Adj[calca].push_back(sapato);
   Adj[calca].push_back(cinto);
   Adj[camisa].push_back(cinto);
   Adj[camisa].push_back(gravata);
   Adj[cinto].push_back(paleto);
   Adj[gravata].push_back(paleto);

   // Transforma em não direcionado
   for (int u = 0; u < N; u++)
      for (list<int>::iterator v = Adj[u].begin(); v != Adj[u].end(); v++)
         Adj[*v].push_back(u);
}
int main () {
    inicializa_grafo();

    if (dfs_bipartido()) cout << endl << 1 << endl;
    else cout << endl << 0 << endl;

    for (int i = 0; i < N; ++i) {
        if (conj[i] == A)      cout << "A";
        else if (conj[i] == B) cout << "B";
        else                   cout << "_";
    }
    cout << endl;
    
    return 0;
}
