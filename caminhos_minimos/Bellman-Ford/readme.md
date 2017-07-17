# Bellman Ford

#### Grafos com arestas negativas, mas sem ciclos negativos

Quando o grafo tem ciclo de custo negativo, a solução ótima é passar por este ciclo infinitas vezes.

Impondo a restrição do caminho passar no máximo uma vez em cada vértice resulta em um problema NP-completo.

Vamos então nos restringir a grafos sem ciclo negativo.

O algoritmo de Bellman-Ford permite arestas de peso negativo.

Retorna valor booleano:

- FALSO, se existe ciclo negativo atingível a partir de s; ou

- VERDADEIRO, caso contrário.

Neste caso, d[] tem as distâncias mínimas de s para cada vértice, e π[] fornece a árvore de caminhos mínimos.

```
BELLMAN-FORD(s):
   INICIALIZAÇÃO(s)
   relaxe todas as arestas |V|-1 vezes
   se alguma aresta (u,v) tem d[v] > d[u] + w[u,v]
      retorne FALSO
   retorne VERDADEIRO
```

```
BELLMAN-FORD(s):
   INICIALIZAÇÃO(s)
   para i <- 1 até |V|-1
      para cada aresta (u,v)
         RELAX(u,v)
   para cada aresta (u,v)
      se d[v] > d[u] + w[u,v]
         retorne FALSO
   retorne VERDADEIRO
```

**Corretude**:
Caso II: Grafo não tem ciclo negativo atingível de s.

Como todo cam. mínimo tem no máximo |V|−1 arestas, e todas as arestas são relaxadas |V|−1 vezes, então, para cada cam. mínimo P, existe subsequência das relaxações que segue a ordem das arestas em P.

```
Ordem relaxação:
   [x - - - -] [- x - - -] [- - x - -] [- - - x -] [- - - - x]
P:  ^             ^             ^             ^             ^
```

Portanto, d[v]=dist(v) para todo vértice v.

Se (u,v) é aresta, d[v]=dist(v)≤dist(u)+w[u,v]=d[u]+w[u,v].

Portanto, vai retornar VERDADEIRO.

Caso II: Tem ciclo negativo C=(v0,v1,..,vk=v0) atingível de s.

Como C é negativo, ∑ki=1w[vi−1,vi]<0.

Por contradição, assuma que retorna VERDADEIRO.

Então, d[vi]≤d[vi−1]+w[vi−1,vi] para todo i.

Somando para toda aresta de C:

∑i=1kd[vi]≤∑i=1kd[vi−1]+∑i=1kw[vi−1,vi].

Como ∑ki=1d[vi]=∑ki=1d[vi−1], temos que ∑ki=1w[vi−1,vi]≥0 (F).

```
BELLMAN-FORD(s):
   INICIALIZAÇÃO(s)
   para i <- 1 até |V|-1        O(V)
      para cada aresta (u,v)    O(VE)
         RELAX(u,v)             O(VE)
   para cada aresta (u,v)       O(E)
      se d[v] > d[u] + w[u,v]   O(E)
         retorne FALSO          O(1)
   retorne VERDADEIRO           O(1)
```

- Complexidade: O(V . E).
