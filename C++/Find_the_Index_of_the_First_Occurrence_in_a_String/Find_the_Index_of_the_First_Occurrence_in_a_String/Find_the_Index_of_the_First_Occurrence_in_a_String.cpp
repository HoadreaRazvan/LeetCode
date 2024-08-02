/*

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

*/


#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0, saveI;
        for (int i = 0; i < haystack.size(); i++)
        {
            saveI = i;
            while (index < needle.size() && haystack[saveI] == needle[index]) {
                index++;
                saveI++;
            }
            if (index == needle.size())
                return i;
            else
                index = 0;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    string haystack = "1leetcode";
    string needle = "leetc";
    int result = solution.strStr(haystack, needle);
    cout << result << endl;
}