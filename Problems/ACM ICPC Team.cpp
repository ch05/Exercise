#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;  //# of people(# of arrays)
    int m;  //# of topics(length of arrays)
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
        
    int max = 0;
    int curr = 0;
    int maxTeam = 0;
    
    for(int i = 0; i < n-1; i++){   //n-1: prevent index overflow in the inner loop
        for(int j = i+1; j < n; j++){   //i+1: prevent self comparison
            curr = 0;
            for(int k = 0; k < m; k++)  //If 1 of the 2 members knows the topic on the current index, increase curr
                if( (topic[i][k] == '1') || (topic[j][k] == '1') ) {
                    curr++;
                    if(max == curr){
                        maxTeam++;
                    }
            }
            if(curr > max){
                max = curr;
                maxTeam = 1;    //Keep the current team that matches the max topics
            }
        }
    }
    cout << max << endl;
    cout << maxTeam << endl;
    return 0;
}