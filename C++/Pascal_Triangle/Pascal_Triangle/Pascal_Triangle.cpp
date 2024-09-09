/*

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]


Constraints:

1 <= numRows <= 30

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        for (int i = 0; i < numRows; i++) {
            triangle[i].resize(i + 1);
            triangle[i][0] = 1;
            triangle[i][i] = 1;
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }
};

int main()
{
    Solution s;
    int numRows = 10;
    vector<vector<int>> result = s.generate(numRows);
    for (int i = 0; i < result.size(); i++, cout << endl)
    {
        for(int j = 0; j < numRows - i - 1; j++)
			cout << " ";
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
    }
}
