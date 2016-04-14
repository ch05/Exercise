#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, curr;
    double total, positive, negative, zero;
    cin >> n;
    total = n;
    positive = 0;
    negative = 0;
    zero = 0;
    while(n--){
        cin >> curr;
        if(curr > 0){
            positive++;
        }
        else if(curr < 0){
            negative++;
        }
        else{
            zero++;
        }
    }
    std::cout.precision(3);
    std::cout << positive/total << std::endl << negative/total << std::endl << zero/total << std::endl;
    return 0;
}
