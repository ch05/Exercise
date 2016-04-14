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
    int left = sticks.size();
    int count = 1;  //# of sticks with the same length
    for(int i = 0; i < sticks.size(); i++){
        if(i != sticks.size() - 1){
            if(sticks[i] == sticks[i+1]){
                count++;
            }
            else{
                std::cout << left << std::endl;
                left -= count;
                count = 1;
            }
                
        }
        else{
            std::cout << count << std::endl;
        }
    }
    return 0;
}
