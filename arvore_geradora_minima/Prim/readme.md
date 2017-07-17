# Prim

O algoritmo de Prim começa em um vértice arbitrário e aumenta uma única árvore, ou seja, olha apenas para o corte em torno da árvore formada.

Se o grafo tem V vértices, irá inserir V−1 arestas na solução.

Se percorremos todo o grafo procurando uma aresta leve, gastaremos O(V + E) para inserir cada aresta. Portanto, a complexidade total será O(V^2 + V . E). Como fazer melhor?

Usando fila com prioridades: Todo vértice que não está na árvore é mantido em uma min-heap, onde a prioridade de um vértice é custo da aresta de menor peso ligando este vértice à árvore. Portanto, o vértice na raiz da heap é ligado por uma aresta leve. Quando incluímos o novo nó u na árvore, atualizamos as prioridades dos nós adjacentes a u ainda não inseridos na árvore.

```pseudo
AGM-PRIM(Adj,n,w[],r):
   para u <- 1 até n                                       O(V)
      key[u] <- oo; pi[u] <- NULO                          O(V)
   key[r] <- 0                                             O(1)
   crie min-heap Q contendo nós com prioridades em key[]   O(V)
   enquanto Q não está vazia                               O(V)
      u <- EXTRACT-MIN(Q)                                  O(V lg V)
      para cada v adjacente a u                            O(V+E)
         se v está na heap e w[u,v] < key[v]               O(E)
            pi[v] <- u                                     O(E)
            key[v] <- w[u,v]                               O(E)
            DECREASE-KEY(Q,v,key[v])                       O(E lg V)
```
Portanto, a complexidade é O(E . log V).

A heap de Fibonacci consegue realizar o DECREASE-KEY em O(1) amortizado, tornando assim o Prim O(E + V . log V). Porém, as constantes são tão altas na heap de Fibonacci que a heap que estudamos é mais rápida na prática (para grafos de tamanho não astronômico).

- Implementação:
  - [C++](main.cpp)
