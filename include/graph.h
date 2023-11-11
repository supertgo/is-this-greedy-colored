#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "memlog.h"

class Graph {
public:
  Graph(int size);
  ~Graph();
  // Esta função imprime as informações do grafo. Se
  // is_greedy for 0, ela imprime "0" indicando que o grafo não é uma coloração
  // gulosa. Caso contrário, imprime "1" seguido pelos rótulos dos vértices que
  // representam uma coloração gulosa.
  void print_graph(int is_greedy);

  // Esta função verifica se o grafo atende aos critérios de coloração gulosa.
  // Ela percorre os vértices do grafo e verifica se o vértice tem uma cor que
  // é a menor possível entre seus vizinhos. Se todos os vértices satisfazem
  // essa condição, a função retorna 1 (verdadeiro), indicando que o grafo é
  // uma coloração gulosa. Caso contrário, retorna 0 (falso).
  int isGreedy();

  // Esta função retorna um ponteiro para o array de vértices do grafo,
  // permitindo que outros códigos acessem os vértices diretamente.
  Vertex *get_vertices();

private:
  //Vértices do grafo
  Vertex *vertices;
  // Array com a coloração inicial
  int *colors;
  int size;
  // Retorna o númer de vértices do grafo.
  int get_size();
  void initialize_graph();
};

#endif
