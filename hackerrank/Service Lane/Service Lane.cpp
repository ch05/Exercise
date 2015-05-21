#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int lane, segment, n;
    vector<int> arr;
    cin >> lane;
    cin >> segment;
    for(int i = 0; i < lane; i++){
        cin >> n;
        arr.push_back(n);
    }
    int min;
    int lo, hi;
    while(segment--){
        min = 3;    //Assume all vehicles can pass at first
        cin >> lo;
        cin >> hi;
        
        for(int i = lo; i <= hi; i++){
            if(arr[i] < min){
                min = arr[i];
            }
            if(min == 1){   //Only bike can pass, no need to further check
                break;
            }
        }
        std::cout << min << std::endl;
    }
    
    return 0;
}
