#include <iostream>
#include <vector>

/* Given an integer array nums sorted in non-decreasing order, remove the duplicates
such that each unique element appears only once. The relative order of the elements 
should be kept the same. Then return the number of unique elements in nums */



/* This ended up being my final solution. It is obviously possible 
to speed this up by not matching nums to new_vector, and simply
return new_vector.size(), but leetcode was insistent on returning
the nums vector. Regardless, this solution runs in O(n) time and is
margianlly faster, (only by a couple of miliseconds,) than the common
swapping solution. What the swapping solution has over mine is that it 
is in-place whereas mine is not. 
*/
class Solution2 {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            if (nums.size() == 1 || nums.size() == 0)
                return nums.size();
            std::vector<int> new_vector;
            new_vector.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++){
                if (nums[i] != nums[i - 1]){
                    new_vector.push_back(nums[i]);
                }
            }
            nums.clear();
            for (int m = 0; m < new_vector.size(); m++){
                nums.push_back(new_vector[m]);
            }

            return nums.size();
        }
};

/* This was my inital solution. However, in a momentary lapse of 
judgement I forgot vector.erase() is actaully an O(n) function as
it must recreate the vector after erasing an elem. Thus this solution
is O(n^2) and unoptimal. */
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        for (int k = 0; k < nums.size(); k++){
                std::cout << nums[k] << " ";
        }
    }
};

int main(){
    Solution2 Duplicate_array;
    //std::vector<int> vector = {1, 1, 1, 2, 3, 3, 4, 4}; // test case one
    //std::vector<int> vector = {1,2,3,4,4,4}; // test case two
    std::vector<int> vector = {1, 1, 2}; // test case three
    Duplicate_array.removeDuplicates(vector);
}

/*

for (int k = 0; k < new_vector.size(); k++){
    std::cout << new_vector[k] << " ";
}

*/