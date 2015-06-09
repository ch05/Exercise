#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m, len, curr;
    int a, b, c;
    cin >> n;
    len = n;
    while(n--){
        cin >> m;
        vector<int> map;
        for(int i = 0; i < len; i++){
            curr = m % 10;
            m = m / 10;
//            std::cout << "a = " << a << ", m = " << m << std::endl;
            map.push_back(curr);                    
        }

        std::cout << map[len-1];
        for(int i = len-2; i > 0; i--){
            if((map[i] > map[i-1]) && (map[i] > map[i+1])){
                std::cout << "X";
            }
            else{
                std::cout << map[i];
            }
        }
        std::cout << map[0] << std::endl;
    }
    
    return 0;
}
