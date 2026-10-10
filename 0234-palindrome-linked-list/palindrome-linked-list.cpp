// 0234. Palindrome Linked List [Easy]
// https://leetcode.com/problems/palindrome-linked-list/
//
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
//
//
//
// Example 1:
//
// Input: head = [1,2,2,1]
// Output: true
//
// Example 2:
//
// Input: head = [1,2]
// Output: false
//
//
//
// Constraints:
//
// 	- The number of nodes in the list is in the range [1, 105].
//
// 	- 0 <= Node.val <= 9
//
//
//
// Follow up: Could you do it in O(n) time and O(1) space?

// --- First accepted solution (2025-06-28) ---


class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=NULL;
        while(curr != NULL){
            Next=curr->next;
            curr->next=prev;
            // p c N
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* cop=new ListNode(0);
        ListNode* tc=cop;
        while(temp){
            ListNode* node = new ListNode(temp->val);
            tc->next=node;
            tc=tc->next;
            temp=temp->next;
        }
        cop=cop->next;
        cop=reverseList(cop);
        ListNode* a=head;
        ListNode* b=cop;
        while(a!=NULL){
            if(a->val != b->val) return false;
            a=a->next;
            b=b->next;
        }
        return true;

        
        
    }
};
