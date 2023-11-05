#ifndef VERTEX_H
#define VERTEX_H

class Vertex {
public:
  int color;
  int label;
  int neighbors_size;
  int *neighbors;

  bool operator>(const Vertex &v2) {
    if (this->color > v2.color)
      return true;

    if (this->color == v2.color && this->label > v2.label)
      return true;

    return false;
  }

  bool operator<(const Vertex &v2) {
    if (this->color < v2.color)
      return true;

    if (this->color == v2.color && this->label < v2.label)
      return true;

    return false;
  }
  bool operator<=(const Vertex &v2) {
    if (this->color < v2.color)
      return true;

    if (this->color == v2.color && this->label <= v2.label)
      return true;

    return false;
  }

  bool operator==(const Vertex &v2) {
    return (this->color && v2.color && this->label && v2.label);
  }
};

#endif // !DEBUG
