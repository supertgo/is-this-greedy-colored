#include "graph.h"
#include "sort.h"
#include <iostream>
#include <sstream>
#include <string>

Graph::Graph(int size) {
  this->vertices = new Vertex[size];
  this->colors = new int[size];
  this->size = size;

  initialize_graph();
}

Graph::~Graph() {
  for (int i = 0; i < this->size; i++) {
    delete[] this->vertices[i].neighbors;
  }
  delete[] vertices;
  delete[] colors;
}

int Graph::isGreedy() {
  int min_color = this->vertices[0].color;
  // Se a primeira cor não é 1, a coloração não é gulosa
  if (min_color != 1)
    return 0;

  for (int i = 0; i < this->get_size(); i++) {
    int color = this->vertices[i].color;

    // Passa para a próxima posição caso a cor do vértice atual seja 1
    if (color == min_color)
      continue;

    int current_vertex_neighbor_size = this->vertices[i].neighbors_size;
    for (int k = min_color; k < color; k++) {
      int found = 0;
      for (int j = 0; j < current_vertex_neighbor_size; j++) {
        int neighbor_color = colors[this->vertices[i].neighbors[j]];

        if (k == neighbor_color) {
          found = 1;
          break;
        }
      }

      if (!found)
        return 0;
    }
  }
  return 1;
}

int Graph::get_size() { return size; }

void Graph::initialize_graph() {
  int neighbors;
  int neighbor;

  for (int i = 0; i < this->size; i++) {
    std::cin >> neighbors;
    this->vertices[i].label = i;
    this->vertices[i].neighbors_size = neighbors;
    this->vertices[i].neighbors = new int[neighbors];

    // Atribui os vizinhos ao vértice do grafo
    for (int j = 0; j < neighbors; j++) {
      std::cin >> neighbor;
      this->vertices[i].neighbors[j] = neighbor;
    }
  }

  int color;
  // Preenche o array de coloração e as cores do vértice
  for (int c = 0; c < this->size; c++) {
    std::cin >> color;

    this->vertices[c].color = color;
    this->colors[c] = color;
  }
}

void Graph::print_graph(int is_greedy) {
  if (!is_greedy) {
    std::cout << "0" << std::endl;
    return;
  }

  std::cout << "1 ";
  for (int i = 0; i < this->size; i++) {
    if (i == this->size - 1) {
      std::cout << this->vertices[i].label << std::endl;
    } else {
      std::cout << this->vertices[i].label << " ";
    }
  }
}

Vertex *Graph::get_vertices() { return this->vertices; }
