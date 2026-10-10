// 0143. Reorder List [Medium]
// https://leetcode.com/problems/reorder-list/
//
// You are given the head of a singly linked-list. The list can be represented as:
//
// L0 → L1 → … → Ln - 1 → Ln
//
// Reorder the list to be on the following form:
//
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.
//
//
//
// Example 1:
//
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
//
// Example 2:
//
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]
//
//
//
// Constraints:
//
// 	- The number of nodes in the list is in the range [1, 5 * 104].
//
// 	- 1 <= Node.val <= 1000

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
// steps: Palindrome ll ; Partititon it ; make a farzi node 
    ListNode* reverselist(ListNode* head ){
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* Next= NULL;
        while(curr != NULL){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* b = reverselist(slow->next);
        ListNode* a = head;
        slow->next=NULL;// for breaking lists
        // we have 2 LL and now merge 'a' and 'b' using 'c' node(new)
        ListNode* c =  new ListNode(0);
        ListNode* tempc=c;
        ListNode* tempa=a;
        ListNode* tempb=b;
        while(tempa != NULL && tempb != NULL ){
            // tempc me tempa daal do phir dono ko aage le jao
            tempc->next=tempa; 
            tempa=tempa->next;
            tempc=tempc->next;
            // tempc me tempb daal do phir dono ko aage le jao
            tempc->next=tempb;
            tempb=tempb->next;
            tempc=tempc->next;
        }
        tempc->next = tempa;
        head= c->next;
    }
};
