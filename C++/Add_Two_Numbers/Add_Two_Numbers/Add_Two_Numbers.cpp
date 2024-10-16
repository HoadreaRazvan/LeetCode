/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]


Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* result = new ListNode();
        ListNode* temp = result;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
            {
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else
                if (l2 == nullptr)
                {
                    sum = l1->val + carry;
                    l1 = l1->next;
                }
                else
                {
                    sum = l1->val + l2->val + carry;
                    l1 = l1->next;
                    l2 = l2->next;
                }
            temp->next = new ListNode(sum % 10);
            carry = sum / 10;
            temp = temp->next;

        }
        if (carry == 1)
            temp->next = new ListNode(carry);
        return result->next;
    }
};


int main()
{
    Solution s;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result = s.addTwoNumbers(l1, l2);
    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }
}