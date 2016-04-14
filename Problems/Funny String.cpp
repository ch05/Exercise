#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() { 
    int n;
    cin >> n;
    string input;
    while(n--){
        cin >> input;
        if(input.size() < 2){
            std::cout << "Not Funny\n";
            continue;
        }
        bool notFunny = false;
        int len = input.size();
        for(int i = 1; i < (len-1); i++){
            if( abs(input[i] - input[i - 1]) != abs(input[len-1-i] - input[len-i]) ){        
                std::cout << "Not Funny\n";
                notFunny = true;
                break;
            }
        }
        if(!notFunny){
            std::cout << "Funny\n";
        }

    }
    return 0;
}
