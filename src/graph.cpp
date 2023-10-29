#include "graph.h"
#include "sort.h"
#include <iostream>
#include <sstream>
#include <string>

Graph::Graph(int size) {
  vertices = new Vertex[size];
  colors = new int[size];
  this->size = size;

  initialize_graph();
}

Graph::~Graph() { delete[] vertices; }

// bool isGreedy(Graph* g, int* coloracao) {
//     int num_vertices = g->GetTamanho();
//     int* available_colors = new int[num_vertices];
//     bool* used_colors = new bool[num_vertices];

//     // Initialize available colors and used_colors arrays
//     for (int i = 0; i < num_vertices; i++) {
//         available_colors[i] = 1;  // Initialize available colors to 1 and up
//         used_colors[i] = false;
//     }

//     int a = 0;

//     for (int i = 0; i < num_vertices; i++) {
//         int vertex_color = coloracao[i];
//         used_colors[i] = true;  // Mark the current vertex as used

//         int* neighbors = g->GetVizinhos(i);
//         int num_neighbors = g->GetNumVizinhos(i);

//         // Mark the colors of neighboring vertices as used
//         for (int j = 0; j < num_neighbors; j++) {
//             int neighbor = neighbors[j];
//             if (neighbor < num_vertices) {
//                 used_colors[neighbor] = true;
//             }
//         }

//         // Determine the smallest available color for the current vertex
//         for (int j = 0; j < num_neighbors; j++) {
//             int neighbor_color = coloracao[neighbors[j]];
//             if (neighbor_color < num_vertices) {
//                 available_colors[neighbor_color] = 0;
//             }
//         }

//         int smallest_available_color = -1;
//         for (int j = 1; j <= num_vertices; j++) {
//             if (available_colors[j] == 1) {
//                 smallest_available_color = j;
//                 break;
//             }
//         }

//         if (smallest_available_color == vertex_color) {
//             a++;
//         }

//         // Reset available colors for the next iteration
//         for (int j = 1; j <= num_vertices; j++) {
//             available_colors[j] = 1;
//         }
//     }

//     delete[] available_colors;
//     delete[] used_colors;

//     return a == num_vertices;
// }
bool Find(int x, int *v, int n) {
  for (int i = 0; i < n; i++) {
    if (v[i] == x)
      return 1;
  }
  return 0;
}

int Graph::isGreedy() {
  int min_color = this->vertices[0].color;

  for (int i = 0; i < this->get_size(); i++) {
    if (this->vertices[i].color == min_color) {
      continue;
    } else {
      int current_vertex_neighbor_size = this->vertices[i].neighbors_size;
      int color = this->vertices[i].color;

      for (int k = 0; k < this->get_size() && this->vertices[k].color < color;
           k++) {
        int found = 0;
        for (int j = 0; j < current_vertex_neighbor_size; j++) {
          int neighbor_color = colors[this->vertices[i].neighbors[j]];

          if (this->vertices[k].color == neighbor_color) {
            found = 1;
          }
        }

        if (!found)
          return 0;
      }
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

    for (int j = 0; j < neighbors; j++) {
      std::cin >> neighbor;
      this->vertices[i].neighbors[j] = neighbor;
    }
  }

  int color;
  for (int c = 0; c < this->size; c++) {
    std::cin >> color;

    this->vertices[c].color = color;
    this->colors[c] = color;
  }
}

void Graph::print_graph(int is_greedy) {
  if (!is_greedy) {
    std::cout << "0" << std::endl;
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

void Graph::graph_info() {
  for (int i = 0; i < this->size; i++) {
    std::cout << "Vertex: " << this->vertices[i].label << " with color "
              << this->vertices[i].color << std::endl;

    std::cout << "Neighbors: ";
    for (int j = 0; j < this->vertices[i].neighbors_size; j++) {
      std::cout << this->vertices[i].neighbors[j] << " ";
    }

    std::cout << std::endl;
  }
}

Vertex *Graph::get_vertices() { return this->vertices; }
