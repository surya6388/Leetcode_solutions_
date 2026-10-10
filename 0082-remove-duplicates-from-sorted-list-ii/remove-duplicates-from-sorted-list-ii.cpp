// 0082. Remove Duplicates from Sorted List II [Medium]
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
//
// You are given the head of a sorted linked list.
//
// Delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
// Return the linked list sorted as well.
//
//
//
// Example 1:
//
// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
//
// Example 2:
//
// Input: head = [1,1,1,2,3]
// Output: [2,3]
//
//
//
// Constraints:
//
// 	- The number of nodes in the list is in the range [0, 300].
//
// 	- -100 <= Node.val <= 100
//
// 	- The list is guaranteed to be sorted in ascending order.

// --- First accepted solution (2026-08-09) ---

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
    
       ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;   // last non-duplicate node
        ListNode* curr = head;    // current node
        while (curr != NULL) {
            // detect duplicate sequence
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }
            // if duplicates were found
            if (prev->next != curr) {
                prev->next = curr->next; // skip all duplicates
            } else {
                prev = prev->next; // move normally
            }
            curr = curr->next;
        }
        return dummy->next;
    }  
    
};
