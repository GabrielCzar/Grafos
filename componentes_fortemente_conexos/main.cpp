#include <iostream>
#include <list>
#include <climits>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

enum cores {branco,cinza,preto};

vector <list<int> > Adj;
vector <list<int> > AdjT;
vector <int> cor, pi, tempo_inicio, tempo_fim;
list<int> ord_topologica;

int N;
int tempo;

void le_grafo_lst () {
   string linha;
   for (int u = 0; getline(cin,linha); u++) {
      const string s = linha;
      Adj.push_back(list<int>());
      string::const_iterator ini = s.begin(), fim;
      if (ini == s.end()) continue;
      do {
         fim = find(ini,s.end(),' ');
         Adj[u].push_back(atoi(string(ini,fim).c_str()));
         ini = fim + 1;
      } while (fim != s.end());
   }
}

void gerar_list_trans(){
      for (int i = 0; i < N; i++)
         for (list<int>::iterator it = Adj[i].begin(); it != Adj[i].end(); it++)
            AdjT[*it].push_back(i);
}

void dfs_visit (int u){
    cor[u] = cinza;
    tempo_inicio[u] = tempo;
    tempo++;
    for(list<int>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++){
        if(cor[*it] == branco){
            pi[*it] = vert;
            DFS_Visit(*it);
        }
    }
    cor[u] = preto;
    tempo_fim[u] = tempo;
    tempo++;
    ord_topologica.push_front(vert);
}

void dfs (){
    for(int i = 0; i < N; i++){
        cor[i] = branco;
        pi[i] = -1;
    }
    tempo = 1;

    for(int i = 0;i < N;i++){
        if(cor[i] == branco){
           dfs_visit(i);
        }
    }
}

bool dfs_visit_transposto (int u){
    cout << u << " ";
    cor[u] = cinza;
    for(list<int>::iterator it = AdjT[u].begin(); it != AdjT[u].end(); it++){
        if(cor[*it] == branco){
            pi[*it] = u;
            dfs_visit_transposto (*it);
        }
    }
    cor[u] = preto;
    return true;
}

void dfs_transposto (){
    for(int i = 0; i < AdjT.size(); i++){
        cor[i] = branco; pi[i] = -1;
    }
    for(list<int>::iterator it = ord_topologica.begin(); it != ord_topologica.end(); it++){
        if(cor[*it] == branco){
            dfs_visit_transposto(*it);
            cout << endl;
        }
    }
}

int main (){
    le_grafo_lst();
    N = Adj.size();

    cor.resize(N, 0);
    pi.resize(N, 0);
    tempo_inicio.resize(N, 0);
    tempo_fim.resize(N, 0);
    AdjT.resize(N);

    dfs();

    gerar_list_trans();

    dfs_transposto();

    return 0;
}
