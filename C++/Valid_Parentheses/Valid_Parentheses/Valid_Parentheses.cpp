/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/


#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stiva;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				stiva.push('(');
			else if (s[i] == ')')
			{
				if (stiva.empty()==true || stiva.top() != '(' )
					return false;
				stiva.pop();
			}
			else if (s[i] == '[')	
				stiva.push('[');
			else if (s[i] == ']')
			{
				if (stiva.empty() == true || stiva.top() != '[')
					return false;
				stiva.pop();
			}
			else if (s[i] == '{')
				stiva.push('{');
			else if (s[i] == '}')
			{
				if(stiva.empty() == true || stiva.top() != '{')
					return false;
				stiva.pop();
			}
			if (i == s.size() - 1)
				return stiva.empty();
		}
		return false;
	}
};


int main()
{
    Solution solution;
	string s = "]";
    bool result = solution.isValid(s);
    cout << result << endl;
}