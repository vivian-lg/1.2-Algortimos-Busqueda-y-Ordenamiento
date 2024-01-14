 /*
 * Compilación con debug:
 *  g++ -std=c++17 *.cpp -Wall -g -o main
 *
 * Compilación para ejecucion:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 * Ejecución con redireccion:
 *  ./main < TestCases/test01.txt
 *  ./main < TestCases/test02.txt
 *  ./main < TestCases/test03.txt
 *  ./main < TestCases/test04.txt
 *
 */

#include "AlgorithmSort.h"
#include "SearchAlgorithm.h"
#include <chrono>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main(void) {

  int size, sortAlgorithm, searchAlgorithm, key;
  cin >> size >> sortAlgorithm >> searchAlgorithm >> key;

  if (size <= 0) {
      std::cerr << "Error: Tamaño de arreglo no válido\n";
      return 1;
  }

  std::vector<int> myVector(size);

  for (int i = 0; i < size; ++i) {
      cin >> myVector[i];
  }

  // Instancia un objeto de la clase AlgorithmSort
  AlgorithmSort<int> sortObj;
  SearchAlgorithm<int> searchObj;

  switch (sortAlgorithm) {
      case 1:
          cout << "Bubble sort:" << endl;
          unsigned int comparisons, swaps;
          sortObj.bubbleSort(myVector, size, comparisons, swaps);
          sortObj.printVector(myVector);
          cout << "\tComparaciones: " << comparisons << endl;
          cout << "\tIntercambios: " << swaps << endl;
          break;
      case 2:
          std::cout << "Merge sort:" << endl;
          comparisons = 0;
          sortObj.mergeSort(myVector, 0, size - 1, comparisons);
          sortObj.printVector(myVector);
          cout << "\tComparaciones: " << comparisons << endl;
          break;
      case 3:
          std::cout << "Quick sort:" << endl;
          comparisons = swaps = 0;
          sortObj.quickSort(myVector, 0, size - 1, comparisons, swaps);
          sortObj.printVector(myVector);
          cout << "\tComparaciones: " << comparisons << endl;
          cout << "\tIntercambios: " << swaps << endl;
          break;
      default:
          std::cerr << "Error: Tipo de algoritmo de ordenamiento no válido\n";
          return 1;
  }

int index = -1;
int comparisons = 0;

switch (searchAlgorithm) {
    case 1:
        std::cout << "Búsqueda Secuencial: " << std::endl;
        index = searchObj.busquedaSecuencialVectorOrdenado(myVector, key, comparisons);
        break;
    case 2:
        cout << "Búsqueda Binaria: " << std::endl;
        index = searchObj.busquedaBinaria(myVector, key, comparisons);
        break;
    default:
        std::cerr << "Error: Tipo de algoritmo de búsqueda no válido\n";
        return 1;
}

if (index != -1) {
    cout << "Elemento " << key << " encontrado en la posición: " << index
              << endl;
} else {
    cout << "Elemento " << key << " no encontrado en el arreglo" << endl;
}

cout << "Comparaciones: " << comparisons << endl;

  return 0;
}


