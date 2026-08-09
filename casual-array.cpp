#include <iostream>

int searchElement(int arr[], int size, int target);

int main (){
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  std::cout << "Array elements: ";
  for(int i = 0; i < size; i++){
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  int target;
  std::cout << "Enter the element to search: ";
  std::cin >> target;
  searchElement(arr, size, target);
  return 0;
}

int searchElement(int arr[], int size, int target){
  for(int i = 0; i < size; i++){
    if(arr[i] == target){
      std::cout << "Element found at index: " << i << std::endl;
      return i;
    }
  }
  std::cout << "Element not found in the array." << std::endl;
  return -1;
}