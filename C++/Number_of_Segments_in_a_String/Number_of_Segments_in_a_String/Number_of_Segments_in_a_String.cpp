/*
 
Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.



Example 1:

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
Example 2:

Input: s = "Hello"
Output: 1


Constraints:

0 <= s.length <= 300
s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.

*/



#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0,length = s.length();
        for(int i=0;i<length;i++)
			if(s[i] != ' ' && (i == length-1 || s[i+1] == ' '))
				count++;
        return count;
    }
};

int main()
{
    Solution solution;
    string s = "....avv123go 1";
    int result = solution.countSegments(s);
    cout << result << endl;

}