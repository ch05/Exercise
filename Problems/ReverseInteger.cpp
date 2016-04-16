#include <climits>

class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0 ? true : false;
        long result, curr = 0;
        while(x){
            curr = curr * 10 + (x % 10);
            x = x / 10;
        }
        result = curr;
        if(result > INT_MAX || result < INT_MIN){
            return 0;
        }
        return result;
    }
};