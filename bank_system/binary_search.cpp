#include<iostream>
#include <vector>
int binarySearch(std::vector<int>& arr, int target);
int main(){
  std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
  binarySearch(arr, 10);
}


int binarySearch(std::vector<int>& arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  while(low <= high){
    int mid = low + (high - low) / 2; 
    if(arr[mid] == target){
      std::cout <<target <<" at index " << mid;
      return mid;
    }else if(arr[mid] < target){
      low = mid + 1;
    }else{
      high = mid - 1;
    }
}
return -1;
}
