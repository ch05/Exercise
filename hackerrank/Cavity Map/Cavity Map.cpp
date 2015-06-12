#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string input;
    int n, len;
    cin >> n;
    vector<string> map;
    len = n;
    if(n <= 2){
        while(n--){
            cin >> input;
            for(int i = 0; i < len; i++){
                std::cout << input[i];
            }
                std::cout<<std::endl;
        }        
    }
    else{
        while(n--){
            cin >> input;
            map.push_back(input);
        }
        
        for(int i = 0; i < len; i++){   //Print the first row
            std::cout << map[0][i];
        }
        std::cout << std::endl;
        
        for(int i = 1; i < len-1; i++){
            std::cout << map[i][0];
            for(int j = 1; j < len-1; j++){
                if((map[i][j] > map[i][j-1]) && (map[i][j] > map[i][j+1]) && (map[i][j] > map[i-1][j]) && (map[i][j] > map[i+1][j])){
                    std::cout << "X";
                }
                else{
                    std::cout << map[i][j];
                }
            }
            std::cout << map[i][len-1]<< std::endl;
        }
        for(int i = 0; i < len; i++){   //Print the last row
            std::cout << map[len-1][i];
        }
    }
}
