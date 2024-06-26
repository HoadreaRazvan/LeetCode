#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (nums[i] + nums[j] == target)
                    return { i,j };
        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> nums = { 3, 2, 3 };
    int target = 6;
    for (int i : solution.twoSum(nums, target))
        cout << i << " ";
}
