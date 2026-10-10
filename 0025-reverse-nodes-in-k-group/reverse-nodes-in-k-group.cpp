// 0025. Reverse Nodes in k-Group [Hard]
// https://leetcode.com/problems/reverse-nodes-in-k-group/
//
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
//
// You may not alter the values in the list's nodes, only nodes themselves may be changed.
//
//
//
// Example 1:
//
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
//
// Example 2:
//
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
//
//
//
// Constraints:
//
// 	- The number of nodes in the list is n.
//
// 	- 1 <= k <= n <= 5000
//
// 	- 0 <= Node.val <= 1000
//
//
//
// Follow-up: Can you solve the problem in O(1) extra memory space?

// --- First accepted solution (2026-02-09) ---

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(true){
            ListNode* temp = prev;
            for(int i=0;i<k && temp;i++){
                temp = temp->next;
            }
            if(temp==NULL) break;
            // dummy → 1 → 2 → 3 → 4 → 5
            ListNode* curr = prev->next;// 1
            ListNode* Next = curr->next;// 2
            for(int i=1;i<k;i++){
                curr->next = Next->next;   // 1 → 3
                Next->next = prev->next;  // 2 → 1
                prev->next = Next;        // dummy → 2
                Next = curr->next;        // next = 3 
            }
            prev = curr;//  move prev to end of reversed group  
        }
        return dummy->next;
    }
    
};
