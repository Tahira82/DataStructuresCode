//
// Created by Tahira on 11.12.24.
//

#include "Sorting.h"

int * Sorting::BubbleSort(const int array[], int sizeOfArray){
  // Time complexity = O(n^2)
  // (n-1) + (n-2) + ....+ 1 = n(n-1)/2
  int * arrayOut =  new int[sizeOfArray];
  for (int k = 0; k < sizeOfArray; k++) {
    arrayOut[k] = array[k];
  }

  for(int k = 0; k < sizeOfArray - 1; k++) {

    bool bAlreadySorted = true;

    for(int i = 0; i < sizeOfArray - (k + 1); i++){

      int j = i + 1;
      if (arrayOut[i] > arrayOut[j]) {
        int temp = arrayOut[i];
        arrayOut[i] = arrayOut[j];
        arrayOut[j] = temp;

        bAlreadySorted = false;
      }
    }

    if (bAlreadySorted)
      return arrayOut;
  }
  return arrayOut;
}

int * Sorting::SelectionSort(const int array[], int sizeOfArray) {
  // Time complexity = O(n^2)
  // (n-1) + (n-2) + ....+ 1 = n(n-1)/2

  int * arrayOut =  new int[sizeOfArray];
  for (int k = 0; k < sizeOfArray; k++) {
    arrayOut[k] = array[k];
  }

  for(int i = 0; i < (sizeOfArray - 1); i++) {
    for(int j = i + 1; j < sizeOfArray; j++) {
      if (arrayOut[i] > arrayOut[j]) {
        int temp = arrayOut[i];
        arrayOut[i] = arrayOut[j];
        arrayOut[j] = temp;
      }
    }
  }
  return arrayOut;
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

  cout << "The bubble sorted array is: ";
  int * Sort = objSort.BubbleSort(arr, size);
  for (int i = 0; i < size; i++) {
    cout << Sort[i] << " ";
  }
  cout << endl;

  cout << "The sorted array is: ";
  for (int i = 0; i < size; i++) {

    cout << arr[i] << " ";

  }
  cout << endl;

  int * SSort = objSort.SelectionSort(arr, size);
  cout << "The selection sorted array is: ";
  for (int i = 0; i < size; i++) {

    cout << SSort[i] << " ";
  }
  cout << endl;

  delete [] arr;
  delete [] Sort;
  delete [] SSort;
  arr = nullptr;
  Sort = nullptr;
  SSort = nullptr;
  return 0;
}