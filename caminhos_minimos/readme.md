# Caminhos Minimos

#### **Problema dos Caminhos Mínimos com Mesma Origem**:

Seja G um grafo orientado com pesos nas arestas, e s um vértice de G. Para cada vértice v de G, encontrar um caminho mínimo (com menor soma dos pesos) de s até v (árvore de cam. mínimos).

Encontrar cam. mínimo entre par de vértices s e t é caso particular.

Armazenamos em w[u,v] o peso de cada aresta (u,v).

Denotamos por dist(v) o tamanho do cam. mínimo de s até v.

Para cada vértice v, armazenamos em d[v] um limite superior para dist(v), ou seja, os algoritmos sempre mantém dist(v)≤d[v].

d[v] é inicializado com ∞, exceto d[s] que é inicializado com 0.

Para cada vértice v, armazenamos em π[v] o predecessor de v na árvore de caminhos mínimos.

#### **Operação de relaxação de arestas**: A operação RELAX tenta melhorar a estimativa em d[v].

```
RELAX(u,v):
   se d[v]  > d[u] + w[u,v]
      d[v] <- d[u] + w[u,v]
      pi[v] <- u
```

#### Veremos três algoritmos baseados em relaxação:

- G é acíclico: relaxação em [ordem topológica](topologica/readme.md).

- Não tem pesos negativos: algoritmo de [Dijkstra](djikstra/readme.md).

- Tem pesos negativos, mas não tem ciclos negativos:
algoritmo de [Bellman-Ford](bellman-ford/readme.md).
