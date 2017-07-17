#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta {
   int u, v, peso;
};

enum enum_cor { branco, preto, cinza };

int tam;
int * cor;

bool dfs_visit (vector< list<Aresta> > Adj, int u, int v) {
   cor[u] = cinza;
   for (list<Aresta>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++) {
        if (cor[(*it).u] == branco){
            if ((*it).u == v)
                return true;
            dfs_visit(Adj, (*it).u, v);
        }
   }
   return false;
}

int mesma_componente(vector< list<Aresta> > Adj, int u, int v) {
    tam = Adj.size();
    cor = new int[tam];

    for (int i = 0; i < tam; i++)
        cor[i] = branco;

    if (dfs_visit(Adj, u, v))
        return true;
    return false;
}

