#include <iostream>
#include <map>
using namespace std;

static std::map<int, int> heightMap;
static int Max;
/**
* @param cycles of growth
* @param the current max height stored in dictionary
* @return height after the given cycles(begin from 0)
*/
int height(int n, int max) {
    if(n == 0){ //base case
        return 1;
    }
    int cycles = 0;
    int height = 0;
    std::map<int,int>::iterator iterator = heightMap.find(n);
    if( iterator == heightMap.end()){    //The target height is not found in the map
        std::map<int,int>::iterator maxIt = heightMap.find(max);
        int maxCycle = maxIt->first;
        int maxHeight = maxIt->second;
        while(max < n){
            if(maxCycle % 2 == 0){ //Even cycle, the tree grows a meter
                maxCycle++;
                maxHeight *= 2;
                heightMap.insert(std::pair<int, int>(maxCycle, maxHeight));
            }
            else{   //Odd cycle, the tree doubles its height
                maxCycle++;
                maxHeight++;
                heightMap.insert(std::pair<int, int>(maxCycle, maxHeight));
            }
            max++;
        }
        return maxHeight;
    }
    else{   //The target height is already in the map
        return iterator->second;
    }
}
int main() {
    //Insert the base case into the map, initialize the global variable to base case
    heightMap.insert(std::pair<int,int>(0, 1));
    Max = 0;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n, Max) << endl;
        if(n > Max){    //Update the Max for faster calculation
            Max = n;
        }
    }
}
