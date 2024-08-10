/*

Given a string s, find the length of the longest
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/


#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
   // int lengthOfLongestSubstring(string s) {
   //     string str = "";
   //     int max = 0;
   //     if(s.length() == 1)
			//return 1;
   //     for (int i = 0; i < s.length(); i++)
   //     {        
   //         str += s[i];
   //         for (int j = 0; j < str.length() - 1; j++)
   //         {
   //             if (s[i] == str[j])
   //             {
   //                 cout<<str<<endl;
   //                 if (max < (int)str.length() - 1)
   //                     max = str.length() - 1;
   //                 i = i- str.length()-2-j;
   //                 cout<<i<<" "<<j<<endl;
   //                 break;
   //             }
   //         }
   //         
   //     }
   //     if (max < (int)str.length())
			//max = str.length();
   //     return max;
   // }

    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); ++right) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};


int main()
{
    Solution s;
    string str = "dvdff";
    int result = s.lengthOfLongestSubstring(str);
    cout << result << endl;
}
