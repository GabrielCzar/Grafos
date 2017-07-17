# Ordem Topologica

#### Grafos direcionados acíclicos (DAGs)

```
INICIALIZAÇÃO(s):
   para todo vértice v, faça d[v] <- oo, pi[v] <- NULO
   d[s] <- 0

DAG-SHORTEST-PATH(s):
   INICIALIZAÇÃO(s)
   encontre ordenação topológica para os vértices
   para cada vértice u em ordem topológica
      para cada v em Adj[u]
         RELAX(u,v)
```

**Corretude**: Se (s,v1),(v1,v2),…,(vk−1,vk) é um cam. mínimo de s até vk, então aplicando RELAX nesta ordem obtemos d[vk]=dist(vk).

Se (u,v) é uma aresta, então u precede v na ordenação topológica.

Se (vi−1,vi) e (vi,vi+1) são arestas, então (vi−1,vi) é relaxada antes de (vi,vi+1), pois na ord. topológica vi−1 precede vi, e vi precede vi+1.

Portanto, ao final do alg. temos d[v]=dist(v) p/ todo vértice v.

(e os predecessores fornecem a árvore de caminhos mínimos)
```
INICIALIZAÇÃO(s):
   para todo vértice v, faça d[v] <- oo, pi[v] <- NULO
   d[s] <- 0

DAG-SHORTEST-PATH(s):
   INICIALIZAÇÃO(s)                                O(V)
   encontre ordenação topológica para os vértices  O(V+E)
   para cada vértice u em ordem topológica         O(V)
      para cada v em Adj[u]                        O(V+E)
         RELAX(u,v)                                O(E)
```
- Complexidade: O(V + E).
