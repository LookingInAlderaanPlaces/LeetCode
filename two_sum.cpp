#include <iostream>
#include <vector>
#include <unordered_map>

class two_sum_n
{
public:
    std::vector <int> two_sum(std::vector<int>& nums, int target){
        std::unordered_map<int, int> map;
        std::vector<int> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if (map.find(x) == map.end())
            {
                map[nums[i]] = i;
            }
            else{
                arr.push_back(map.at(x));
                arr.push_back(i);
                std::cout << "indices are: " << arr[0] << " and " << arr[1];
                return arr;
            }
        }
        std::cout << "no target found";
        return arr;
    }
    
};




// a standard, simple, albeit slow solution for the common two sum problem. N^2.
class two_sum_n_squared
{
public:
    std::vector <int> two_sum(std::vector<int>& nums, int target){
        std::vector<int> arr;
        int i = 0;
        while (i < nums.size() - 1) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] + nums[i] == target){
                    arr.push_back(i);
                    arr.push_back(j);
                    std::cout << "numbers are: " << nums[i] << " " << nums[j] << std::endl;
                    return arr;
                }
            }
            i++;
        }
        std::cout << "no target found";
        return arr;
    }
};


int main(){
 std::vector<int> array = {1, 4, 7, 9, 12, 15, 10};
 int target;
 //two_sum_n_squared solution;
 two_sum_n solution;
 std::cout << "enter target: ";
 std::cin >> target;
 solution.two_sum(array, target);
}