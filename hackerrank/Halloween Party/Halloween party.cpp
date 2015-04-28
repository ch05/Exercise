#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    long cut;   //Range of cut is [2, 10^7], which may overflow int
    while(n--){
        cin >> cut;        
        long first = (cut/2);
        long second = cut - first;
        std::cout << first * second << std::endl;
    }
    return 0;
}
