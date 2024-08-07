/*

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:

Input: head = [1,1,2]
Output: [1,2]

Example 2:

Input: head = [1,1,2,3,3]
Output: [1,2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
			return nullptr;
        ListNode* current = head;
        ListNode* result = new ListNode(current->val);
        ListNode* save = result;
        while (current->next != nullptr)
        {
            if (current->val != current->next->val)
            {
                result->next = new ListNode(current->next->val);
                result = result->next;
            }
			current = current->next;
		}
        return save;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(2,new ListNode(1,new ListNode(1)));
    ListNode* result = s.deleteDuplicates(head);
    while(result != nullptr)
	{
		cout<<result->val<<endl;
		result = result->next;
	}
}