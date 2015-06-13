#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, len, curr;
    cin >> n;
    len = n;
    int square[n][n];
    while(n--){
        for(int i = 0; i < len; i++){
            cin >> curr;
            square[len-n-1][i] = curr;
        }
    }
    int first, second, result;
    int k = len-1;
    for(int i = 0; i < len; i++){
        first += square[i][i];
        second += square[k][i];
        k--;        
    }
    result = abs(first - second);
    std::cout << result;
    return 0;
}
