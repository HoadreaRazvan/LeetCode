/*

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:

Input: rowIndex = 0
Output: [1]

Example 3:

Input: rowIndex = 1
Output: [1,1]


Constraints:

0 <= rowIndex <= 33


Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};

int main()
{
    Solution s;
    int rowIndex = 3;
	vector<int> result = s.getRow(rowIndex);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
