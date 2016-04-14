#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int input;
    int orig;
    
    while(n--){
        cin >> input;
        orig = input;
        int rightMostDigit;
        
        int counter = 0;
        while(input != 0){
            rightMostDigit = input % 10;
            input = input/10;
            if(rightMostDigit == 0){    //Divided by 0 is undefined
                continue;
            }
            if(orig % rightMostDigit == 0){
                counter++;
            }
        }
        cout << counter << endl;        
    }
    return 0;
}
