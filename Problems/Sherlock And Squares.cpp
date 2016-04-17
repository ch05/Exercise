#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, A, B, count;
    double sqrt1, sqrt2, temp;
    cin >> T;
    for(int i = 0; i < T; i++){
        count = 0;
        cin >> A >> B;        
        sqrt1 = sqrt(A);
        sqrt2 = sqrt(B);
        
        count += floor(sqrt2) - ceil(sqrt1) + 1;
        cout << count << endl;
    }

    return 0;
}
