#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,budget,price,wrapper;
    int chocolate, currWrapper, newChocolate;
    cin>>t;

    while(t--){
        cin>>budget>>price>>wrapper;
        chocolate = budget/price;
        currWrapper = chocolate;

        while(currWrapper >= wrapper){
            newChocolate = currWrapper/wrapper;
            chocolate += newChocolate;
            currWrapper -= newChocolate * wrapper;
            currWrapper += newChocolate;
        }
        std::cout << chocolate << std::endl;
    }
    return 0;
}
