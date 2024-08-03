/*

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


Constraints:

1 <= nums.length <= 10^4
-104 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-104 <= target <= 10^4

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1, mid;
		while (start <= end)
		{
			mid = (end + start) / 2;
			if (target == nums[mid])
				return mid;
			else
				if (target < nums[mid])
					end = mid - 1;
				else
					start = mid + 1;
		}
		return nums[mid] > target ? mid : mid + 1;
	}
};

int main()
{
	Solution solution;
	vector<int> nums = { 1, 3, 5, 6 };
	int target = 2;
	int result = solution.searchInsert(nums, target);
	cout << result;
}