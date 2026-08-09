#include <iostream>

void sort(int arr[], int size);

int main(){
  int arr[] = {1,2,5,4,3,6,10,8,9,7};
  int size = sizeof(arr)/sizeof(arr[0]);
  for(int element : arr){
    std::cout << element << " ";
  }
  std::cout << std::endl;
  sort(arr, size);
  for(int element : arr){
    std::cout << element << " ";
  }
  return 0;
}

void sort(int arr[], int size){
  for(int i = 0; i < size - 1; i++){
    for(int j = 0; j < size -1; j++){
      if(arr[j] > arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }else{
        continue;
      }
    }
  }
}