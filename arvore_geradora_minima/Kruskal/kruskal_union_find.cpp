#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    struct Node * pai;
    int rank;
    char id; // identificador
};

Node * make_set(char id) {
    Node * node = new Node();
    node->id = id;
    node->rank = 0;
    node->pai = node;
    return node;
}

Node * find_set(Node * x) {
    if (x->pai == x)
        return x->pai;
    x->pai = find_set(x->pai);
}

void uf_union(Node * x, Node * y) {
    Node * nodex = find_set(x);
    Node * nodey = find_set(y);
    if (nodex->rank > nodey->rank)
        nodey->pai = nodex;
    else {
        nodex->pai = nodey;
        if (nodex->rank == nodey->rank)
            nodey->rank++;
    }
}

struct Aresta {
   int u, v, peso;
};


bool comp(Aresta i, Aresta j){
    return i.peso < j.peso;
}

// 0.018454 segundos
// Entrada: lista de adjacências 'Adj'.
list<Aresta> kruskal_union_find(vector< list<Aresta> > Adj){
    int tam = Adj.size();
    vector<Aresta> arestas;
    list<Aresta> solucao;

    for (int i = 0; i < tam; ++i)
        for (list<Aresta>::iterator it = Adj[i].begin(); it != Adj[i].end(); it++)
            if (i < it->v) arestas.push_back(*it);

    sort(arestas.begin(), arestas.end(), comp);

    Node * conjunto [tam];
    for (int i = 0; i < tam; ++i) conjunto[i] = make_set(i);

    for (vector<Aresta>::iterator it = arestas.begin(); it != arestas.end(); it++) {
        if (find_set(conjunto[it->u]) != find_set(conjunto[it->v])){
            solucao.push_back(*it);
            uf_union(conjunto[it->u], conjunto[it->v]);
        }
    }

    for (int i = 0; i < tam; ++i) delete conjunto[i];


    return solucao;
}
