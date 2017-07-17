# Árvore Geradora Mínima

Considere um grafo não direcionado com pesos positivos nas arestas. Escolha um conjunto de arestas que conecta todos os vértices gastando o mínimo possível.

Toda solução ótima forma um grafo conexo sem ciclos (**árvore**). Se a solução tem ciclo, podemos melhorar a solução removendo qualquer aresta do ciclo, pois isso mantém o grafo conexo.

Este problema pode ser resolvido com algoritmo guloso. Veremos duas estratégias: Prim e Kruskal.

**Subproblema**: floresta (conjunto de árvores). Ao inserir aresta (que não forma ciclo), unimos duas árvores.

**Escolha gulosa ótima**: qual critério sempre escolhe uma aresta que está contida em alguma solução ótima do subproblema?

Dado um conjunto de vértices S, o **corte** de S é o conjunto de arestas que ligam vértices em S com vértices fora de S. Um corte respeita o conjunto A de arestas se não contém arestas de A. Vamos considerar apenas cortes que respeitam o subproblema.

Uma **aresta leve** é uma aresta de peso mínimo no corte.

**Teorema**: Toda aresta leve está em alguma solução ótima do subproblema.

**Prova**: Seja O uma solução ótima do subproblema que não contém a aresta leve (u,v). Seja C o ciclo formado pela inclusão de (u,v) em O. Como pelo menos duas arestas de C pertencem ao corte, existe aresta (p,q) em C com custo não menor que (u,v). Portanto, trocando (p,q) por (u,v) em O não pioramos a solução.

- [Prim](Prim/readme.md)
- [Kruskal](Kruskal/readme.md)
