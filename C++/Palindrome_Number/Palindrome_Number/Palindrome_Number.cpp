#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        else
        {
            int nou = 0, save = x;
            while (save)
            {
                nou = nou * 10 + save % 10;
                save /= 10;
            }
            if (nou == x)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    int number = 1234321;
    bool result = solution.isPalindrome(number);
    cout << result;
}

