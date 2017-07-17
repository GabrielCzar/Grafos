# Kruskall

O algoritmo de Kruskal escolhe a aresta de menor peso que não forma ciclo no subproblema.

```
AGM-KRUSKAL(Adj,n,w[]):
   A <- {}                                                    O(1)
   ordene as arestas em ordem não-decrescente de peso         O(E lg E)
   para cada aresta (u,v) nesta ordem,                        O(E)
      se u e v estão em componentes distintos do grafo (V,A)  O(?)
         A <- A U {(u,v)}                                     V-1=O(V)
   retorne A                                                  O(1)

```

Podemos testar se u e v estão no mesmo componente fazendo uma busca em largura/profundidade em O(V+E). Portanto, o algoritmo será O(E(V + E)) = O(V . E). Possível fazer melhor?

Usando ED para conjuntos disjuntos, modelamos cada árvore do subproblema como um conjunto disjunto. Então, verificamos em O(1) amortizado se dois nós estão no mesmo conjunto. Além disso, em O(1) amortizado fazemos a união de dois conjuntos (quando uma aresta é inserida na solução).

```
AGM-KRUSKAL(Adj,n,w[]):
   A <- {}                                                 O(1)
   para v <- 1 até n, faça MAKE-SET(v)                     O(V)
   ordene as arestas em ordem não-decrescente de peso      O(E lg E)
   para cada aresta (u,v) nesta ordem,                     O(E)
      se FIND-SET(u) != FIND-SET(v)                        O(E)
         A <- A U {(u,v)}                                  O(V)
         UNION(u,v)                                        O(V)
   retorne A                                               O(1)

```
Portanto, a complexidade é O(E . log E) = O(E . log V) (igual ao Prim).

- Implementação:
  - [DFS](kruskal_dfs.cpp)
  - [Union-Find](kruskal_union_find.cpp)
