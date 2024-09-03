/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]


Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> digitToChar = { "","","abc","def","ghi","jkl","mno","pqrs", "tuv", "wxyz" };
        vector<string> result;
        string current;
        backtrack(digits, 0, current, result, digitToChar);
        return result;
    }

private:
    void backtrack(string digits, int index, string current, vector<string>& result, const vector<string> digitToChar) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        string letters = digitToChar[digit];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result, digitToChar);
            current.pop_back();
        }
    }
};

int main()
{
    Solution s;
    string digits = "23";
    vector<string> result = s.letterCombinations(digits);
    for (string str : result) {
		cout << str << endl;
	}
}