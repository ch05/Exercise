#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
int lonelyinteger(vector < int > a) {
return 0;

}
int main() {
    int num, curr;
    cin >> num;
    std::map<int,int> hash;
    std::map<int, int>::iterator it;
    while(num--){
        cin >> curr;
        it = hash.find(curr);
        if(it == hash.end()){
            hash.insert(std::pair<int, int>(curr, 1));
        }
        else{   //The key value pair exists already
            hash[curr]++;
        }
    }
    for(it = hash.begin(); it != hash.end(); it++){
        if(it->second == 1){
            std::cout << it->first << std::endl;
            break;
        }
    }
    return 0;
}
