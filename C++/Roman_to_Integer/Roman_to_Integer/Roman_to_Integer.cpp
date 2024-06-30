#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int integer = 0;
        map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        for (int i = 0; i < s.length(); i++)
        {
            if (i + 1 < s.length() && map[s[i]] < map[s[i + 1]]) {
                integer += map[s[i + 1]] - map[s[i]];
                i += 1;
            }
            else
                integer += map[s[i]];
        }
        return integer;
    }
};

int main()
{
    Solution solution;
    string roman = "LVIII";
    int result = solution.romanToInt(roman);
    cout << result;
}
