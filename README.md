# Grafos
- Um grafo é par **G = (V, E)**, onde
	- **V** é um conjunto finito de elementos chamados **_vértices_**
	-  **E** é um conjunto finito de pares _não-ordenados_ de vértices chamados de **_arestas_** (edges).

- Representação
	- Matriz de Adjacências  
	_É uma matriz quadrada A de ordem |V|, cujas linhas e colunas são indexadas pelos vértices em V, e tal que:_
	```
	A[i, j] = { 1 se (i, j) pertence a E,
		        { 0 caso contrário.
	```
	![](img/matriz_adj.png)

	![](img/matriz_adj_dir.png)

	- Lista de Adjacências  
	_Para cada vértice **v**, temos uma linked list Adj[v] dos 	vértices adjacentes a **v**, ou seja, **w** aparece em Adj[v] se **(v, w)** é uma aresta de G. Os vértices podem estar em qualquer ordem em uma lista._

	![](img/lista_adj.png)

	![](img/lista_adj_dir.png)

---

#### [Busca em Largura](busca_em_largura/readme.md)
#### [Busca em Profundidade](busca_em_profundidade/readme.md)
#### [Verificacao de Bipartição](bipartido/readme.md)
#### [Mostrar um caminho de um nó a outro](caminho/readme.md)
#### [Ordenação topológica](ordenacao_topologica/readme.md)
