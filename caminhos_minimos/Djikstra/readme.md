# Djikstra

#### Grafos com ciclos e pesos não negativos

Quando o grafo tem ciclos, mas não tem aresta com peso negativo, podemos aplicar o algoritmo de Dijkstra.

Funciona de forma similar ao Prim.

Em cada iteração:

Mantém em S os vértices que estão na árvore de caminhos mínimos encontrada até então.

Encontra vértice u fora de S que esteja mais próximo dos vértices em S, e insere u em S.

Atualiza d[u] e π[u].

```
DIJKSTRA(s):
   INICIALIZAÇÃO(s)
   S <- {}
   Q <- min-heap inicializadas com vértices com chaves d[]
   enquanto Q não está vazia
      u <- EXTRACT-MIN(Q)
      S <- S U {u}
      para cada vértice v em Adj[u] e fora de S
         RELAX(u,v)
         DECREASE-KEY(Q,v,d[v])
```

Corretude: Basta mostrar que todo vértice v em S tem d[v]=dist(v).

Vamos mostrar por indução no número de vértices em S.

Vale após a 1a iteração, pois S={s} e d[s]=0.

Considere o instante em que u∉S com menor d[u] é escolhido para entrar em S. Assuma por contradição que d[u]>dist(u).

Seja P um cam. mínimo de s até u, y o 1o vértice de P fora de S, e x o predecessor de y em P.

Subestrutura ótima: P contém um cam. mínimo até y.

Se existisse cam. melhor para y, P não seria mínimo para u.

Como a aresta (x,y) foi relaxada logo após x entrar em S, e d[x]=dist(x) por hip. de indução, temos que d[y]=dist(y).

Como os pesos são não negativos, temos que dist(u)≥dist(y).

Portanto, d[u]>dist(u)≥dist(y)=d[y].

Contradição, pois u tem o menor d dentre os vértices fora de S.

```
DIJKSTRA(s):
   INICIALIZAÇÃO(s)                                      O(V)
   S <- {}                                               O(1)
   Q <- min-heap inicializadas c/ vértices c/ chaves d[] O(V)
   enquanto Q não está vazia                             O(V)
      u <- EXTRACT-MIN(Q)                                O(V lg V)
      S <- S U {u}                                       O(V)
      para cada vértice v em Adj[u] e fora de S          O(V+E)
         RELAX(u,v)                                      O(E)
         DECREASE-KEY(Q,v,d[v])                          O(E lg V)
```

- Complexidade: O((V+E)logV).

- Grafo denso: O(V2logV). Grafo esparso: O(VlogV).

Usando heap de Fibonacci podemos fazer o DECREASE-KEY em O(1). (porém, com constante altas)

```
DIJKSTRA(s):
   INICIALIZAÇÃO(s)                                      O(V)
   S <- {}                                                 O(1)
   Q <- min-heap inicializadas c/ vértices c/ chaves d[] O(V)
   enquanto Q não está vazia                             O(V)
      u <- EXTRACT-MIN(Q)                                O(V lg V)
      S <- S U {u}                                         O(V)
      para cada vértice v em Adj[u] e fora de S          O(V+E)
         RELAX(u,v)                                      O(E)
         DECREASE-KEY(Q,v,d[v])                          ----> O(E)
```

- Complexidade: O(VlogV+E).

- Grafo denso: O(V2logV). Grafo esparso: O(VlogV).
