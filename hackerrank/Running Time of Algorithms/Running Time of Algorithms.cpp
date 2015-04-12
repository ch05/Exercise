#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int swap = 0;
    int n, curr;
    vector<int> arr;
    cin >> n;
    
    while(n--){
        cin >> curr;
        arr.push_back(curr);       
    }
    
    for(int i = 1; i < arr.size(); i++){
        for(int j = 0; j <= i - 1; j++){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap++;
            }
        }
    }
    std::cout << swap << std::endl;
    
    return 0;
}
