/*

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.


Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n1 = 0, n2 = 0, size1 = nums1.size(), size2 = nums2.size();
        while (i < size1 && j < size2 && i + j <= (size1 + size2 + 1) / 2)
        {
            if (nums1[i] < nums2[j])
            {

                n1 = n2;
                n2 = nums1[i];
                i++;
            }
            else
            {
                n1 = n2;
                n2 = nums2[j];
                j++;
            }
        }
        while (i < size1 && i + j <= (size1 + size2 + 1) / 2)
        {
            n1 = n2;
            n2 = nums1[i];
            i++;
        }
        while (j < size2 && i + j <= (size1 + size2 + 1) / 2)
        {
            n1 = n2;
            n2 = nums2[j];
            j++;
        }
        return (size1 + size2) % 2 == 0 ? (n1 + n2) / 2.0 : size1 + size2 == 1 ? n2 : n1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = { 1,3 };
    vector<int> nums2 = { 2 };
    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
}
