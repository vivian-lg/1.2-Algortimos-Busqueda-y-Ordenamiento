#ifndef _ALGORITHM_SORT_H_
#define _ALGORITHM_SORT_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

template <class T>
class AlgorithmSort {
  public:
    AlgorithmSort();
    ~AlgorithmSort();
    void printVector(std::vector<T> A);

    void bubbleSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap);
    void mergeSort(std::vector<T> &A, int low, int high, unsigned int &compara);
    void quickSort(std::vector<T> &A, int low, int high, unsigned int &compara, unsigned int &swap);
   

  private:
    void merge(std::vector<T> &A, int low, int m, int high, unsigned int &compara);
    int partition(std::vector<T> &A, int low, int high, unsigned int &compara, unsigned int &swap);

// semilla del generador de numeros aleatorios (time-based)
    unsigned seed; 
    // generador de numeros aleatorios (Mersenne Twister 64 bits)
    std::mt19937_64 gen;
   
};

template<class T>
AlgorithmSort<T>::AlgorithmSort() {
  // semilla del generador de numeros aleatorios (time-based)
  seed = std::chrono::system_clock::now().time_since_epoch().count();
  // generador de numeros aleatorios (Mersenne Twister 64 bits)
  std::mt19937_64 gen;
  // inicializar el generador con la semilla creada
  gen.seed(seed);
}


template<class T>
AlgorithmSort<T>::~AlgorithmSort() {

}

// Imprime en pantalla los elementos del vector
template<class T>
void AlgorithmSort<T>::printVector(std::vector<T> A) {
    std::cout << "Los elementos del vector ordenado son: " << std::endl;
    for(int i = 0; i < (int)A.size(); i++) {
      std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// O(n^2)
template<class T>
void AlgorithmSort<T>::bubbleSort(std::vector<T> &A, int n, unsigned int &compara, unsigned int &swap) {
  compara = swap = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      compara++;
      if (A[j] > A[j+1]) {
        std::swap(A[j], A[j+1]);
        swap++;
      }
    }
  }
}


template<class T>
void AlgorithmSort<T>::merge(std::vector<T> &A, int low, int m, int high, unsigned int &compara) {
  int i, j, k;
  // Calcular el tamaño de los vectores L y R
  int n1 = m - low + 1;
  int n2 = high - m;
  // Crear los vectores auxiliares L y R
  std::vector<T> L(n1);
  std::vector<T> R(n2);
  for (i = 0; i < n1; i++) L[i] = A[low + i];
  for (j = 0; j < n2; j++) R[j] = A[m + 1 + j];
  // Mezclar los vectores L y R de forma ordenada
  i = j = 0;
  k = low;
  while (i < n1 && j < n2) {
    compara++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
    k++;
  }
  // Copia los elementos restantes de L y R
  while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
  }
}

//O(n log n)
template<class T>
void AlgorithmSort<T>::mergeSort(std::vector<T> &A, int low, int high, unsigned int &compara) {
  if (low < high) {
    // encontrar el punto medio
    int m = low + (high - low) / 2;
    // Dividir el problema en mitades
    mergeSort(A, low, m, compara);
    mergeSort(A, m+1, high, compara);
    // Mezcla de ambas mitades
    merge(A, low, m, high, compara);
  }
}

template<class T>
int AlgorithmSort<T>::partition(std::vector<T> &A, int low, int high, unsigned int &compara, unsigned int &swap) {
  T pivot = A[high];
  int i = low - 1;
  for (int j = low; j < high-1; j++) {
    compara++;
    if (A[j] < pivot) {
      i++;
      std::swap(A[i], A[j]);
      swap++;
    }
  }
  std::swap(A[i+1], A[high]);
  swap++;
  return i + 1;  
}


template<class T>
void AlgorithmSort<T>::quickSort(std::vector<T> &A, int low, int high, unsigned int &compara, unsigned int &swap) {
  if (low < high) {
    // encontrar la particion del vector
    int pi = partition(A, low, high, compara, swap);
    // ordenar la particion izquierda y derecha
    quickSort(A, low, pi - 1, compara, swap);
    quickSort(A, pi + 1, high, compara, swap);
  }
}

#endif   // _ALGORITHM_SORT_H_