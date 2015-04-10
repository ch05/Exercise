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
//        std::cout << "line 15, n = " << n << std::endl;
        cin >> input;
        if(input.size() %2 == 1){   //Odd length
            std::cout << -1 << std::endl;
            continue;
        }
        
        int len = input.size();
        int half = input.size()/2;
        vector<char> sub1;
        vector<char> sub2;
        
//        std::cout << "line 26" << std::endl;
        
        for(int i = 0; i < len; i++){
            if(i < half){
                sub1.push_back(input[i]);
            }
            else{
                sub2.push_back(input[i]);
            }
        }
//        std::cout << "line 36" << std::endl;
        
        //Testing
/*        for(int i = 0; i < half; i++){
            std::cout << sub1[i] << " ";
        }
        std::cout << std::endl;
        for(int i = 0; i < half; i++){
            std::cout << sub2[i] << " ";
        }
        std::cout << std::endl;
        //Testing
*/        
        vector<char>::iterator it1;
        vector<char>::iterator it2;
        int diffCount = 0;
        
        
        for(int i = 0; i < half; i++){
//            std::cout << "line 54, i =" << i << std::endl;
            it2 = find(sub2.begin(), sub2.end(), sub1[i]);
            if(it2 != sub2.end()){
//                std::cout << "line 58" << std::endl;
                //it1 = find(sub1.begin(), sub1.end(), sub1[i]);
                //sub1.erase(it1);
                sub2.erase(it2);
            }
            else{
//                std::cout << "line 65" << std::endl;
                diffCount++;
            }
        }
        std::cout << diffCount << std::endl;
    }
    return 0;
}
