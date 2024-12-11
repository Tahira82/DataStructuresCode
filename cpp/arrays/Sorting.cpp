//
// Created by Tahira on 11.12.24.
//

#include "Sorting.h"

int * Sorting:: BubbleSort(int array[], int sizeOfArray){
  for(int k = 0; k < sizeOfArray - 1; k++) {
    for(int i = 0; i < sizeOfArray - (k + 1); i++){
      int j = i + 1;
      if (array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
  return array;
}

int main() {

  int size = 0;
  cout << "Please input the size of array: "<<std::endl;
  cin >> size;
  int * arr = new int[size];
  cout << "Please input the array elements to sort: "<< std::endl;
  for (int i = 0; i < size; i++)
    {
      cin >> arr[i];
    }
  Sorting objSort;

  cout << "The sorted array is: ";
  for (int i = 0; i < size; i++) {
    cout << objSort.BubbleSort(arr, size)[i] << " ";
  }
  cout << endl;


  return 0;
}