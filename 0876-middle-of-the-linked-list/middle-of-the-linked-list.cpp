// 0876. Middle of the Linked List [Easy]
// https://leetcode.com/problems/middle-of-the-linked-list/
//
// Given the head of a singly linked list, return the middle node of the linked list.
//
// If there are two middle nodes, return the second middle node.
//
//
//
// Example 1:
//
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
//
// Example 2:
//
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
//
//
//
// Constraints:
//
// 	- The number of nodes in the list is in the range [1, 100].
//
// 	- 1 <= Node.val <= 100

// --- First accepted solution (2025-06-26) ---

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
    int sizeOfLL(ListNode* head){
        ListNode* temp = head;
        int n=0;
        while(temp != NULL){
            n++;
            temp=temp->next;
        }
        return n;
    }
    ListNode* middleNode(ListNode* head) {
        int size= sizeOfLL(head);
        ListNode* temp = head;
        if(size == 0) return  head;
        else{
            int idx=size/2;
            for(int i=1;i<=idx;i++){
                temp=temp->next;
            }
            return temp;
        }
        
    }
};
