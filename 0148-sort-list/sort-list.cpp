// 0148. Sort List [Medium]
// https://leetcode.com/problems/sort-list/
//
// Given the head of a linked list, return the list after sorting it in ascending order.
//
//
//
// Example 1:
//
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
//
// Example 2:
//
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
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
// 	- The number of nodes in the list is in the range [0, 5 * 104].
//
// 	- -105 <= Node.val <= 105
//
//
//
// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

// --- First accepted solution (2025-06-28) ---

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
// steps: break the linked list into  two LL at left middle ; then sort the both LL using recursion ; use merge2LL
    ListNode* merge(ListNode* a,ListNode* b){
    ListNode* c = new ListNode(-1);
    ListNode* temp=c;
    while(a != NULL && b != NULL){
        if(a->val <= b->val){
            temp->next=a;
            a=a->next;
            temp=temp->next;
        }
        else{
            temp->next=b;
            b=b->next;
            temp=temp->next;
        }
    }
    if(a == NULL) temp->next=b;
    else temp->next=a;
    return c->next;
}
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        // breaking LL into 2 LL
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast->next != NULL && fast->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // Now slow is at left middle
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next=NULL;
        // sorting using recursion
        a = sortList(a);
        b = sortList(b);
        ListNode* c= merge(a,b);
        return c;
    }
};
