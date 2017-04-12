#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

enum COR {BRANCO, CINZA, PRETO};
enum VERTICES {A, B, C, D, E, F, G, H};

vector <list <int>> Adj;
list <int> ord_topologica;
vector <int> cor, pi, d, f;
int tempo = 0;
int N;

bool topologic_sort_visit (int u) {
    cor[u] = CINZA;
    d[u] = tempo;
    tempo = tempo + 1;

    for (list<int>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++) {
        if (cor[*it] == BRANCO) {
            pi[*it] = u;
            topologic_sort_visit (*it);
        } if (cor[*it] == CINZA)
            return false;
    }

    cor[u] = PRETO;
    f[u] = tempo;
    tempo = tempo + 1;
    ord_topologica.push_front(u);
    return true;
}

bool topologic_sort () {
    for (int i = 0; i < N; i++) {
        cor[i] = BRANCO;
        pi[i] = -1;
    }
    tempo = 0;
    for (int i = 0; i < N; i++)
        if (cor[i] == BRANCO)
            if (!topologic_sort_visit(i))
                return false;
    return true;
}

void le_grafo_lst(){
   string linha;
   for (int u = 0; getline (cin, linha); u++) {
      const string s = linha;
      Adj.push_back (list<int>());
      string::const_iterator ini = s.begin(), fim;
      if (ini == s.end())
          continue;
      do {
         fim = find (ini, s.end(), ' ');
         Adj[u].push_back (atoi (string (ini,fim).c_str()));
         ini = fim + 1;
      } while (fim != s.end());
   }
}

int main(){
    le_grafo_lst();

    cor.resize (Adj.size(), 0);
    pi.resize (Adj.size(), 0);
    d.resize (Adj.size(), 0);
    f.resize (Adj.size(), 0);
    N = Adj.size();

    if (topologic_sort()){
        cout << true << endl;
        for (list<int>::iterator it = ord_topologica.begin();
             it != ord_topologica.end();
                it++)
            cout << *it << " ";
    } else cout << false;

    return 0;
}

