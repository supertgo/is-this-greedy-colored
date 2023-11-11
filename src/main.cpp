#include "graph.h"
#include "sort.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>

int main() {
  char sort_method;
  int graph_size;
  char lognome[100] = "/tmp/greedy.out";
  int regmem = 1;
  std::cin >> sort_method;
  std::cin >> graph_size;

  iniciaMemLog(lognome);

  if (regmem) {
    ativaMemLog();
  } else {
    desativaMemLog();
  }

  defineFaseMemLog(0);
  Graph graph(graph_size);
  switch (sort_method) {
  case 'b':
    defineFaseMemLog(1);
    bubble_sort(graph.get_vertices(), graph_size);
    break;
  case 's':
    defineFaseMemLog(1);
    selection_sort(graph.get_vertices(), graph_size);
    break;
  case 'i':
    defineFaseMemLog(1);
    insertion_sort(graph.get_vertices(), graph_size);
    break;
  case 'q':
    defineFaseMemLog(1);
    quick_sort(graph.get_vertices(), graph_size);
    break;
  case 'm':
    defineFaseMemLog(1);
    merge_sort(graph.get_vertices(), graph_size);
    break;
  case 'p':
    defineFaseMemLog(1);
    heap_sort(graph.get_vertices(), graph_size);
    break;
  case 'y':
    defineFaseMemLog(1);
    cocktail_sort(graph.get_vertices(), graph_size);
  default:
    throw std::runtime_error("Método de classificação desconhecido");
    break;
  };

  const int is_greedy = graph.isGreedy();

  graph.print_graph(is_greedy);

  return finalizaMemLog();
}
