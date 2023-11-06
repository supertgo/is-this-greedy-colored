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

template <typename T> void merge(T *items, int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  T *leftArr = new T[n1];
  T *rightArr = new T[n2];

  for (i = 0; i < n1; i++)
    leftArr[i] = items[left + i];
  for (j = 0; j < n2; j++)
    rightArr[j] = items[mid + 1 + j];

  i = 0;
  j = 0;
  k = left;
  while (i < n1 && j < n2) {
    if (leftArr[i] <= rightArr[j]) {
      items[k] = leftArr[i];
      i++;
    } else {
      items[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    items[k] = leftArr[i];
    i++;
    k++;
  }

  while (j < n2) {
    items[k] = rightArr[j];
    j++;
    k++;
  }

  delete[] leftArr;
  delete[] rightArr;
}

template <typename T> void merge_sort_helper(T *items, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    merge_sort_helper(items, left, mid);
    merge_sort_helper(items, mid + 1, right);

    merge(items, left, mid, right);
  }
}

template <typename T> void merge_sort(T *items, int size) {
  merge_sort_helper(items, 0, size - 1);
}

template <typename T> void heapify(T *items, int size, int root) {
  int largest = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;

  if (left < size && items[left] > items[largest])
    largest = left;

  if (right < size && items[right] > items[largest])
    largest = right;

  if (largest != root) {
    swap(items[root], items[largest]);

    heapify(items, size, largest);
  }
}

template <typename T> void heap_sort(T *items, int size) {
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(items, size, i);

  for (int i = size - 1; i > 0; i--) {
    swap(items[0], items[i]);

    heapify(items, i, 0);
  }
}

template <typename T>
void cocktail_sort(T *items, int size) {
  int swapped = true;
  int start = 0;
  int end = size - 1;

  while (swapped) {
    swapped = false;

    for (int i = 0; i < end; i++) {
      if (items[i] > items[i + 1]) {
        swap(items[i], items[i + 1]);
        swapped = true;
      }
    }

    if (!swapped)
      break;

    swapped = false;

    for (int i = end - 1; i >= start; --i) {
      if (items[i] > items[i + 1]) {
        swap(items[i], items[i + 1]);
        swapped = true;
      }
    }

    ++start;
  }
}

template <typename T> void swap(T &x, T &y) {
  T temp = x;
  x = y;
  y = temp;
}

#endif // !DEBUG
