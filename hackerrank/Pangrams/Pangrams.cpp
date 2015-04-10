#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<bool> alphabet;  //A vector that keeps track of if a letter has been seen before
    for(int i = 0; i < 26; i++){
        alphabet.push_back(false);
    }
    
    string input;

    while(!cin.eof()){
        cin >> input;
        int len = input.size();
        int intVal;
        
        for(int i = 0; i < len; i++){
            intVal = (int)input[i];
            if((intVal <= 122) && (intVal >=97)){   //Upper case letter in Ascii
                alphabet[intVal - 97] = true;
            }
            else if((intVal >= 65) && (intVal <= 90)){  //Lower case letter in Ascii
                alphabet[intVal - 65] = true;
            }            
        }
    }
    for(int i = 0; i < 26; i++){
        if(alphabet[i] == false){            
            std::cout << "not pangram\n";            
            return 0;
        }
    }    
    std::cout << "pangram\n";        
            
    return 0;
}
