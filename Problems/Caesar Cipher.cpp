#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string plain, cipher;
    int length, shift, diff, curr;
    cin >> length;
    cin >> plain;
    cin >> shift;
    cipher = plain;

    while(shift > 26){
        shift -= 26;
    }
    for(int i = 0; i < length; i++){
        if((plain[i] < 65) || ((plain[i] > 90) && (plain[i] < 97)) || (plain[i] > 122) ){
            continue;
        }
         curr = plain[i] + shift;
        if( ((curr <= 90) && (curr >= 65)) && ((plain[i] <= 90) && (plain[i] >= 65)) ){ //A-Z 65-90
            cipher[i] = curr;
        }
        if( ((curr <= 122) && (curr >= 97)) && ((plain[i] <= 122) && (plain[i] >= 97))){  //a-z 97-122)
            cipher[i] = curr;
        }
        else if(((plain[i] <= 122) && (plain[i] >= 97)) && (curr > 122)){
            diff = curr - 122;
            cipher[i] = 97 + diff - 1;
        }
        else if(((plain[i] <= 90) && (plain[i] >= 65)) && (curr > 90)){
            diff = curr - 90;
            cipher[i] = 65 + diff - 1;
        }
    }
    
    for(int i = 0; i < length; i++){
        std::cout << cipher[i];
    }
    return 0;
}
