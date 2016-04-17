#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void findMatch(vector<string> & Grid, vector<string> & Pattern, int R, int C, int r, int c){
    for(int i = 0; i < R; i++){
        vector<size_t> pos;
        
        size_t found = Grid[i].find(Pattern[0]); //Find the first row in Pattern that matches Grid
        while(found != string::npos){   //Exhaust all potential match on the same row of Grid and record their idx
            pos.push_back(found);
            found = Grid[i].find(Pattern[0], found+1);    //Begin new search from index found+1
        }
    
        if((i+r) > R){  //The remaining part of Grid has less rows than Pattern, no matching
            cout << "NO" << endl;
            return;
        }
        while(pos.size()){
            size_t currPos = pos.back();
            bool allMatch = true;   //One way flag
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    if(Grid[i+j][k+currPos] != Pattern[j][k]){
                        allMatch = false;
                        break;
                    }
                }                          
            }
            pos.pop_back();
            if(allMatch){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;

    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> Grid(R);
        for(int i = 0; i < R; i++){
           cin >> Grid[i];
        }
        
        int r;
        int c;
        cin >> r >> c;
        vector<string> Pattern(r);
        for(int i = 0; i < r; i++){
           cin >> Pattern[i];
        }        

        findMatch(Grid, Pattern, R, C, r, c);        
    }

    return 0;
}