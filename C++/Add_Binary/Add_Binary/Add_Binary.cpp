/*

Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = 1, carry = 0, d1, d2;
        string result = "";
        if (a.size() < b.size())
            while (b.size() - a.size())
                a = '0' + a;
        else
            while (a.size() - b.size())
                b = '0' + b;
        while (i <= a.size())
        {
            d1 = a[a.size() - i] - '0';
            d2 = b[b.size() - i] - '0';
            result = to_string((d1 + d2 + carry) % 2) + result;
            carry = (d1 + d2 + carry) / 2;
            i++;
        }
        if (carry == 1)
            result = '1' + result;
        return result;
    }
};

int main()
{
    Solution s;
    string a = "100";
    string b = "110010";
    string result = s.addBinary(a, b);
    cout << result << endl;
}
