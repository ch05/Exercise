#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, len;
    cin >> n;
    len = n;
    while(n--){
        int space = n;
        int sharp = len - n;
        for(int i = 0; i < space; i++){
            std::cout << " ";
        }
        for(int i = 0; i < sharp; i++){
            std::cout << "#";
        }
        std::cout << std::endl;
    }
    return 0;
}
