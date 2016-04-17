#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    unsigned long t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        unsigned long b;
        unsigned long w;
        cin >> b >> w;
        unsigned long x;
        unsigned long y;
        unsigned long z;
        cin >> x >> y >> z;
        
        unsigned long bConv = y + z;
        unsigned long wConv = x + z;
        
        unsigned long result = b * min(x, bConv) + w * min(y, wConv);
        cout << result << endl;
    }
    return 0;
}
