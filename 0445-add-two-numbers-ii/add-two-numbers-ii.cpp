// 0445. Add Two Numbers II [Medium]
// https://leetcode.com/problems/add-two-numbers-ii/
//
// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//
//
// Example 1:
//
// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]
//
// Example 2:
//
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]
//
// Example 3:
//
// Input: l1 = [0], l2 = [0]
// Output: [0]
//
//
//
// Constraints:
//
// 	- The number of nodes in each linked list is in the range [1, 100].
//
// 	- 0 <= Node.val <= 9
//
// 	- It is guaranteed that the list represents a number that does not have leading zeros.
//
//
//
// Follow up: Could you solve it without reversing the input lists?

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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* Next = head->next;
            head->next = prev;
            prev = head;
            head = Next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1: reverse both lists
        l1 = reverse(l1);
        l2 = reverse(l2);
        // Step 2: add like normal
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        // Step 3: reverse result
        return reverse(dummy->next);
    }
};
