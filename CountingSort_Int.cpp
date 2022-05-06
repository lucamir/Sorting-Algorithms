#include <iostream>
using namespace std;

class CountingSort {
  int* A;
  int dim;
  int AddElement(int x);

 public:
  CountingSort(int dim) {
    this->dim = dim;
    A = new int();
    for (int i = 0; i < dim; i++)
      A[i] = AddElement(i);
  }

  void Sort();
  void Print();

  int getMax();
  int getMin();
};

int CountingSort::getMax() {
  int max = A[0];
  for (int i = 1; i < dim; i++)
    if (max < A[i]) max = A[i];
  return max;
}

int CountingSort::getMin() {
  int min = A[0];
  for (int i = 1; i < dim; i++)
    if (min > A[i]) min = A[i];
  return min;
}

int CountingSort::AddElement(int x) {
  int temp;
  cout << "Add a new element n." << x + 1 << " @> ";
  cin >> temp;
  return temp;
}

void CountingSort::Sort() {
  int max = getMax();
  int min = getMin();
  int range = max - min + 1;

  int* C = new int[range];
  for (int i = 0; i <= range; i++)
    C[i] = 0;

  for (int i = 0; i < dim; i++)
    C[A[i] - min]++;
  for (int i = 1; i <= range; i++)
    C[i] += C[i - 1];

  int B[dim];
  for (int i = dim - 1; i >= 0; i--) {
    B[C[A[i] - min] - 1] = A[i];
    C[A[i] - min]--;
  }

  for (int i = 0; i < dim; i++)
    A[i] = B[i];
}

void CountingSort::Print() {
  cout << endl;
  for (int i = 0; i < dim; i++)
    cout << A[i] << " ";
  cout << endl
       << endl;
}