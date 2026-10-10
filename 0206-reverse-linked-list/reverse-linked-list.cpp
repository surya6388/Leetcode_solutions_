// 0206. Reverse Linked List [Easy]
// https://leetcode.com/problems/reverse-linked-list/
//
// Given the head of a singly linked list, reverse the list, and return the reversed list.
//
//
//
// Example 1:
//
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
//
// Example 2:
//
// Input: head = [1,2]
// Output: [2,1]
//
// Example 3:
//
// Input: head = []
// Output: []
//
//
//
// Constraints:
//
// 	- The number of nodes in the list is the range [0, 5000].
//
// 	- -5000 <= Node.val <= 5000
//
//
//
// Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

// --- First accepted solution (2025-06-28) ---


class Solution {
public:
ListNode* getNode(ListNode* head, int idx){
    ListNode* temp=head;
    for(int i=1;i<=idx;i++){
        temp=temp->next;
    }
    return temp;
}
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp){ // (temp => temp != NULL)
            temp=temp->next;
            n++;
        }
        int i=0;
        int j=n-1;
        while(i<j){
            ListNode* left = getNode(head,i);
            ListNode* right= getNode(head,j);
            int temp=left->val;
            left->val=right->val;
            right->val = temp;
            i++;
            j--;
        }
        return head;
    }
};
