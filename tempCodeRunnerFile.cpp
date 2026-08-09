#include <iostream>

void sort(int arr[], int size);

int main()
{
    int arr[] = {1,4,5,6,8,10};
    for(int elem : arr){
        std::cout << elem << " ";
    }
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr, size);
    
    for(int elem : arr){
        std::cout << elem << " ";
    }
    return 0;
}

void sort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for (int j = 0; i < size - 1; i++) {
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}