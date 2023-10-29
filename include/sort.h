#ifndef SORT_H
#define SORT_H

template <typename T> void bubble_sort(T *items, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 1; j < size - i; j++) {
      if (items[j - 1] > items[j]) {
        swap(items[j - 1], items[j]);
      }
    }
  }
}

template <typename T> void selection_sort(T *items, int size) {
  for (int i = 0; i < size; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (items[min] > items[j]) {
        min = j;
      }
    }

    swap(items[i], items[min]);
  }
}

template <typename T> void insertion_sort(T *items, int size) {
  for (int i = 1; i < size; i++) {
    int j = i - 1;
    T aux = items[i];

    while (j >= 0 && aux < items[j]) {
      items[j + 1] = items[j];
      j--;
    }
    items[j + 1] = aux;
  }
}

template <typename T>
void partition(int left, int right, int *i, int *j, T *items) {
  T pivot, w;
  *i = left;
  *j = right;

  pivot = items[(*i + *j) / 2];

  do {
    while (pivot > items[*i])
      (*i)++;
    while (pivot < items[*j])
      (*j)--;

    if (*i <= *j) {
      w = items[*i];
      items[*i] = items[*j];
      items[*j] = w;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

template <typename T> void sort(int left, int right, T *items) {
  int i, j;

  partition(left, right, &i, &j, items);

  if (left < j)
    sort(left, j, items);
  if (i < right)
    sort(i, right, items);
}

template <typename T> void quick_sort(T *items, int size) {
  sort(0, size - 1, items);
}

template <typename T> void merge_sort(T *items, int size) {}

template <typename T> void heap_sort(T *items, int size) {}

template <typename T> void swap(T &x, T &y) {
  T temp = x;
  x = y;
  y = temp;
}

#endif // !DEBUG
