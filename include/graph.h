#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include <string>

class Graph {
public:
  Graph(int size);
  ~Graph();
  void print_graph(int is_greedy);
  void graph_info();
  int isGreedy();
  Vertex* get_vertices();

private:
  Vertex *vertices;
  int *colors;
  int size;
  int get_size();
  void initialize_graph();
};

#endif
