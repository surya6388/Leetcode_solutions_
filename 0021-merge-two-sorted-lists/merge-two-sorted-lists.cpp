// 0021. Merge Two Sorted Lists [Easy]
// https://leetcode.com/problems/merge-two-sorted-lists/
//
// You are given the heads of two sorted linked lists list1 and list2.
//
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
//
// Return the head of the merged linked list.
//
//
//
// Example 1:
//
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
//
// Example 2:
//
// Input: list1 = [], list2 = []
// Output: []
//
// Example 3:
//
// Input: list1 = [], list2 = [0]
// Output: [0]
//
//
//
// Constraints:
//
// 	- The number of nodes in both lists is in the range [0, 50].
//
// 	- -100 <= Node.val <= 100
//
// 	- Both list1 and list2 are sorted in non-decreasing order.

// --- First accepted solution (2025-06-27) ---

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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) { 
        ListNode* tempA=a;
        ListNode* tempB=b;
        ListNode* c = new ListNode(-1);
        ListNode* tempC=c;
        while(tempA != NULL && tempB != NULL){
            if(tempA->val <= tempB->val){
                ListNode* t = new ListNode(tempA->val);
                tempC->next=t;
                tempC = t;
                tempA = tempA->next;
            }
            else{
                ListNode* t = new ListNode(tempB->val);
                tempC->next=t;
                tempC = t;
                tempB=tempB->next;
            }
        }
        if(tempA == NULL){
            tempC->next=tempB;
        }
        else{
            tempC->next = tempA;
        }
        return c->next;


        


        
    }
};
