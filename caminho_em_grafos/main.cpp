#include <iostream>
#include <list>
#include <queue>
#include <limits.h>

#define N 8
#define DENSIDADE 0.1

using namespace std;

enum enum_cor { branco, preto, cinza };
enum Vertices {s, w, r, t, x, v, u, y};
//0  1  2  3  4  5  6  7

list<int> Adj[N];
int cor[N]; //Cor
int d[N]; // distancia
int pi[N]; //predecessor

void m(int s) {
    cout << "Vertice visitado: "
         << s << "\t"
         << "Pai: "
         << pi[s] <<  "\t"
         << "Distancia: "
         << d[s] << "\n";
}

void bfs (list<int> Adj[], int s) {
    for (int i = 0; i < N; i++) {
        if (i != s) {
            cor[i] = branco;
            d[i] = INT_MAX;
            pi[i] = -1;
        }
    }
    cor[s] = cinza;
    d[s] = 0;
    pi[s] = -1;

    queue<int> q;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        for (list<int>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++){
            if (cor[*it] == branco){
                cor[*it] = cinza;
                d[*it] = d[u] + 1;
                pi[*it] = u;
                q.push(*it);

                //m(*it);
            }
        }
        q.pop();
        cor[u] = preto;
    }
}

void grafo_aleat_dir_lst() {
    // srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (((double) rand() / RAND_MAX) < DENSIDADE)
                Adj[i].push_back(j);
}

// Grafo não direcionado do exemplo da busca em largura:
void inicializa_grafo()
{

    // s, w, r, t, x, v, u, y
    //0  1  2  3  4  5  6  7

    Adj[s].push_back(w);
    Adj[s].push_back(r);
    Adj[r].push_back(s);
    Adj[r].push_back(v);
    Adj[v].push_back(r);
    Adj[w].push_back(s);
    Adj[w].push_back(t);
    Adj[w].push_back(x);
    Adj[t].push_back(w);
    Adj[t].push_back(x);
    Adj[t].push_back(u);
    Adj[x].push_back(w);
    Adj[x].push_back(t);
    Adj[x].push_back(u);
    Adj[x].push_back(y);
    Adj[u].push_back(t);
    Adj[u].push_back(x);
    Adj[u].push_back(y);
    Adj[y].push_back(x);
    Adj[y].push_back(u);

    // Grafo Bi-direcionado
}

void print_path (list<int> G[], int s, int v) {
    if (v == s)
        cout << s << " ";
    else if (pi[v] == -1)
        cout << "Nao existe caminho de S a V" << endl;
    else{
        print_path (G, s, pi[v]);
        cout << v << " ";
    }

    // Complexidade: O(comprimento do caminho) = O(V ).
    // Exercício: Imprima o caminho mais curto, em número de aresta, de s a v .
}

int main() {
    //grafo_aleat_dir_lst();
    inicializa_grafo ();
    bfs (Adj, 0);

    print_path (Adj, s, t);

    return 0;
}

