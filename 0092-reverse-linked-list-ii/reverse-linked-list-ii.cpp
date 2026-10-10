// 0092. Reverse Linked List II [Medium]
// https://leetcode.com/problems/reverse-linked-list-ii/
//
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
//
//
//
// Example 1:
//
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
//
// Example 2:
//
// Input: head = [5], left = 1, right = 1
// Output: [5]
//
//
//
// Constraints:
//
// 	- The number of nodes in the list is n.
//
// 	- 1 <= n <= 500
//
// 	- -500 <= Node.val <= 500
//
// 	- 1 <= left <= right <= n
//
//
//
// Follow up: Could you do it in one pass?

// --- First accepted solution (2025-06-28) ---


class Solution {
public:
// steps: break the list into 3 lists : 1 to l-1, l to r, r+1 to n
    ListNode* reverselist(ListNode* b){
        ListNode* prev=NULL;
        ListNode* curr=b;
        ListNode* Next=NULL;
        while(curr != NULL){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) { 
        if(left == right) return head; 
        ListNode* temp=head;
        ListNode* a=NULL;
        ListNode* b= NULL;
        ListNode* c=NULL;
        ListNode* d=NULL;
        int n=1;
        while(temp){
            if(n==left-1) a=temp;
            if(n==left) b=temp;
            if(n==right) c=temp;
            if(n==right+1) d=temp;
            temp=temp->next;
            n++;
        }
        if(a != NULL) a->next=NULL;
        c->next = NULL; 
        c = reverselist(b);
        if(a != NULL) a->next=c;
        b->next=d;
        if(a!= NULL) return head;
        return c;

    }
};
