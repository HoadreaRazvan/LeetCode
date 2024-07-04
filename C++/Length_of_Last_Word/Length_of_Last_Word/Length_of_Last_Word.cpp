#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ok = 0, k = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && ok == 1)
                return k;
            if (s[i] != ' ')
            {
                ok = 1;
                k++;
            }
        }
        return k;
    }
};

int main()
{
    Solution solution;
    string s = "Hello       World        ";
    int result = solution.lengthOfLastWord(s);
    cout << result << endl;
}