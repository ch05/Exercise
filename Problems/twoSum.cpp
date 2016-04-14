#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    /**    
    * Given an array of integers, find two numbers such that they add up to a specific target number.
    * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
    * You may assume that each input would have exactly one solution.
    *
    * @param The vector containing all the candidate numbers
    * @param The target sum
    * @return The vector containing the two indices corresponding to the two numbers that add up to the sum in ascending order  
    */
    static std::vector<int> twoSum(std::vector<int> &numbers, int target) {
        if(numbers.size() > 1){
            std::vector<int> sorted = numbers;
            std::sort(sorted.begin(), sorted.end());
            int idx1 = 0;
            int idx2 = numbers.size() - 1;

            for(int i = 0; i < sorted.size(); i++){
                std::cout << sorted[i] << std::endl;
            }

            std::vector<int> ret;

            while( (idx1 != idx2)){
                if( (sorted[idx1] + sorted[idx2]) > target){
                    idx2--;
                }
                else if( (sorted[idx1] + sorted[idx2]) < target){
                    idx1++;
                }
                else{
                    //One way flag for marking the index is found, preventing reassining the same index twice
                    //Without the flag the index may change when the first time it's found, and resulting in incorrect answer
                    //Comment the 2nd flag out and run with the large number test to see the above comment
                    bool found1 = false;
                    bool found2 = false;
                    for(int i = 0; i < numbers.size(); i++){
                        if(numbers[i] == sorted[idx1] && found1 == false){
                            idx1 = i;                            
                            found1 = true;
                        }
                        else if(numbers[i] == sorted[idx2] && found2 == false){
                            idx2 = i;                        
                            found2 = true;
                        }
                    }
                    //Make sure the two indices are in ascending order in the result, and add 1 to each as stated in requirement
                    if(idx1 < idx2){
                        ret.push_back(++idx1);
                        ret.push_back(++idx2);    
                    }   
                    else{
                        ret.push_back(++idx2);
                        ret.push_back(++idx1);                        
                    } 
                    
                    return ret;
                }
            }
        }
        
        return std::vector<int>();
    }
};

int main(){
    int target = 200;

    std::vector<int> num;
    num.push_back(150);
    num.push_back(24);
    num.push_back(79);
    num.push_back(50);
    num.push_back(88);
    num.push_back(345);
    num.push_back(3);
    
// [2, 7, 11, 15], 9    -   BASIC
// [3, 2, 4], 6     -   NOT SORTED
// [0, 4, 3, 0], 0  -   MULTIPLE ELEMENTS WITH THE SAME VALUE
// [-1,-2,-3,-4,-5], -8     -   NEGATIVE NUMBER
// [150,24,79,50,88,345,3], 200     -   LARGE NUMBER

    std::vector<int> result = Solution::twoSum(num, target);
    std::cout << result[0] << ", " << result[1] << std::endl;
    std::cout << num[result[0] - 1] << ", " << num[result[1] - 1] << std::endl;

    return 0;
}

/**
* Discussion of solution
* O(n2) runtime, O(1) space – Brute force:
* The brute force approach is simple. Loop through each element x and find if there is another value that equals to target – x. As finding another value requires looping through the rest of array, its runtime complexity is O(n2).
* O(n) runtime, O(n) space – Hash table:
* We could reduce the runtime complexity of looking up a value to O(1) using a hash map that maps a value to its index.
*/