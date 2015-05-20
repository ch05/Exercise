#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//The algorithm tries to find a single character that's shared by both strings
int main() {
    int n, m;
    cin >> n; 
    string a, b;
    bool found;    
    while(n--){
        m = 0;
        found = false;
        cin >> a;
        cin >> b;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for(int i = 0; i < a.length(); i++){
            if(a[i] == a[i+1]){ //Since the string is sorted, we don't double check the same character
                continue;
            }
            
            for(int j = m; j < b.length(); j++){
                if(b[j] < a[i]){    //The string is sorted, b[j] will not be in a if b[j] < a[i]
                    m++;
                    continue;
                }
                if(b[j] == b[j+1]){ //Since the string is sorted, we don't double check the same character
                    continue;
                }
                if(found){  
                    break;
                }
                if(a[i] == b[j]){
                    std::cout << "YES\n";
                    found = true;     
                }
            }
            if(found){
                break;
            }
        }
        if(!found){
            std::cout << "NO\n";    
        }        
    }
    
    return 0;
}
