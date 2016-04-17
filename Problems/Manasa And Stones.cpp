#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, n, a, b;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n;
        cin >> a;
        cin >> b;
        if(n == 1){ //Edge case of 1 stone
            cout << "0" << endl;
            continue;
        }        
        if(a == b){ //Edge case of a and b are the same
            cout << a * (n-1) << endl;
            continue;
        }
        if(a > b){  // Make sure a is the smaller increment amount for the sorted output
            int temp = a;
            a = b;
            b = temp;
        }
        if(n == 2){ //Edge case of 2 stones
            cout << a << " " << b << endl;
            continue;
        }
        n--;
        for(int j = 0; j <= n; j++){
            int curr = (a * (n - j)) + (b * j);
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}