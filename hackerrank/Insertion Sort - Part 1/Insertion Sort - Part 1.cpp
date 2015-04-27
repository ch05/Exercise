#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector <int> & arr) {
for(int i = arr.size() - 1; i >= 0; i--){
std::cout << "insertionSort " << arr[i] << std::endl;
}

}

int main(void) {
  vector <int> arr;
  vector <int> print;
  int len;
  cin >> len;

  for(int arr_i=0; arr_i<len; arr_i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
    print.push_back(temp);
  }
//Test
/*
for(int i = 0; i < len; i++){
std::cout << arr[i] << " ";
}    
std::cout << std::endl;
for(int i = 0; i < len; i++){
std::cout << print[i] << " ";

}        
*/
//Test

//insertionSort(arr);
  int insert = arr[arr.size() - 1];
  for(int i = arr.size() - 2; i >= 0; i--){

    if(insert < arr[i]){
      swap(arr[i], arr[i+1]);
      for(int j = 0; j < arr.size(); j++){
        if(j != i){
          std::cout << arr[j] << " ";
        }
        else{
          std::cout << arr[i+1] << " ";
        }
      }
      std::cout << std::endl;
    }
  }
  //Print out the sorted array
  for(int i = 0; i < len; i++){
  std::cout << arr[i] << " ";
  } 
  return 0;
}
