#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string input;
    cin >> input;
    
    std::string hourstr = input.substr(0,2);
    int time = std::stoi(hourstr);
    
    if(input[8] == 'A'){    //AM
        if(time == 12){ //12AM edge case
            std::cout << "00";
            for(int i = 2; i < input.size() - 2; i++){
                std::cout << input[i];
            }
        }
        else{
            for(int i = 0; i < input.size() - 2; i++){
                std::cout << input[i];
            }
        }                
    }
    else{   //PM 
        if(time == 12){ //12PM edge case
            std::cout << "12";
        }
        else{
            time += 12;
            std::cout << time;            
        }
        for(int i = 2; i < input.size() - 2; i++){
            std::cout << input[i];
        }
    }
    return 0;
}
