/*

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int x = matrix.size();
        int y = matrix[0].size();

        int top = 0, bottom = x - 1;
        int left = 0, right = y - 1;

        int i;

        while (top <= bottom && left <= right) {
            for (i = left; i <= right; ++i)
                result.push_back(matrix[top][i]);
            top++;

            for (i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            right--;

            for (i = right; i >= left && top <= bottom; --i)
                result.push_back(matrix[bottom][i]);
            bottom--;

            for (i = bottom; i >= top && left <= right; --i)
                result.push_back(matrix[i][left]);
            left++;

        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
}
