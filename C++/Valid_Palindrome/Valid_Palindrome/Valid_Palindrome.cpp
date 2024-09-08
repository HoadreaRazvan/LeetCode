/*

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.


Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.


Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        auto isAlphanumeric = [](char c) -> bool {
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
            };

        int left = 0, right = s.length() - 1;
        char leftChar, rightChar;

        while (left < right) {
            while (left < right && !isAlphanumeric(s[left])) {
                left++;
            }

            while (left < right && !isAlphanumeric(s[right])) {
                right--;
            }

            leftChar = (s[left] >= 'A' && s[left] <= 'Z') ? s[left] + ('a' - 'A') : s[left];
            rightChar = (s[right] >= 'A' && s[right] <= 'Z') ? s[right] + ('a' - 'A') : s[right];

            if (leftChar != rightChar) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};


int main()
{
    Solution s;
    string palindrome = "A man, a plan, a canal: Panama";
    bool result = s.isPalindrome(palindrome);
    cout << result << endl;
}
