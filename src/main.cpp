#include "graph.h"
#include "sort.h"
#include <iostream>
#include <sstream>
#include <string>

int main() {
  char sort_method;
  int graph_size;
  std::cin >> sort_method;
  std::cin >> graph_size;

  Graph graph(graph_size);

  //graph.graph_info();

  switch (sort_method) {
  case 'b':
    bubble_sort(graph.get_vertices(), graph_size);
    break;
  case 's':
    selection_sort(graph.get_vertices(), graph_size);
    break;
  case 'i':
    insertion_sort(graph.get_vertices(), graph_size);
    break;
  case 'q':
    quick_sort(graph.get_vertices(), graph_size);
    break;
  case 'm':
    quick_sort(graph.get_vertices(), graph_size);
    break;
  case 'p':
    heap_sort(graph.get_vertices(), graph_size);
    break;
  case 'y':
    insertion_sort(graph.get_vertices(), graph_size);
    break;
  };

  const int is_greedy = graph.isGreedy();

  graph.print_graph(is_greedy);

  return 0;
}
