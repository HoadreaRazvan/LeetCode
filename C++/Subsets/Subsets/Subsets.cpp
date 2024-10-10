/*

Given an integer array nums of unique elements, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        generateSubsets(nums, 0, subset, result);
        return result;
    }

    void generateSubsets(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);
        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            generateSubsets(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
};


int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.subsets(nums);
    for (int i = 0; i < result.size(); i++) {
		cout << "[";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << "]" << endl;
	}
}
