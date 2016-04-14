#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, actual, wanted, curr, onTime;
    cin >> n;
    while(n--){
        onTime = 0;
        cin >> actual;
        cin >> wanted;
        while(actual--){
            cin >> curr;
            if(curr <= 0){
                onTime++;
            }            
        }
        if(onTime >= wanted){
            std::cout << "NO" << std::endl;
            continue;
        }
        std::cout << "YES" << std::endl;
    }
    return 0;
}
