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
        int len = input.length();
        
        if(len == 1){
            std::cout << 0 << std::endl;
            continue;
        }
        
        int count = 0;
        for(int i = 0; i < len / 2; i++){
            int j = input.length() - 1 - i;
            if(input[i] != input[j]){
                count += abs((int)(input[i]) - (int)(input[j]));
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}