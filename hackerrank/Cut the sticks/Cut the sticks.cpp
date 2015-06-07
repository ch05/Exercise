#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, curr;
    vector<int> sticks;
    cin >> n;   //# of sticks
    while(n--){
        cin >> curr;
        sticks.push_back(curr);
    }
    std::sort(sticks.begin(), sticks.end());
    while(sticks.size() != 0){
        int min = sticks[0];
        for(int i = 0; i < sticks.size(); i++){
            std::cout << sticks[i] << " ";
        }
        std::cout << "\nmin in this iteration = " << min << "length left = " << sticks.size() << std::endl;
        int j = 0;
        for(auto i = sticks.begin(); i != sticks.end(); i = i++){
            std::cout << "idx = " << j << "data = " << *i << std::endl;
            j++;
            *i -= min;
            if(*i == 0){
                sticks.erase(i);
                if(sticks.size() != 0){
                i = sticks.begin();    
                }
            }
        }   
    }
    return 0;
}
