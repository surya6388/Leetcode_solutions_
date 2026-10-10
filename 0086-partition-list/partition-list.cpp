// 0086. Partition List [Medium]
// https://leetcode.com/problems/partition-list/
//
// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the two partitions.
//
//
//
// Example 1:
//
// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
//
// Example 2:
//
// Input: head = [2,1], x = 2
// Output: [1,2]
//
//
//
// Constraints:
//
// 	- The number of nodes in the list is in the range [0, 200].
//
// 	- -100 <= Node.val <= 100
//
// 	- -200 <= x <= 200

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
// To do : find nodes lesser than x ; place them in same order and place rest nodes next to them
// steps: make 2 listnode 'lo' and 'hi' with their respective temp(tl,th); if nodes is less connect it to tl and else connect to th; connect tl to th
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp = head;
        ListNode* lo = new ListNode(-1);
        ListNode* hi = new ListNode(-2);
        ListNode* tl=lo;
        ListNode* th=hi;
        while(temp != NULL){
            if(temp->val < x){
                tl->next=temp;
                temp=temp->next;
                tl=tl->next;
            }
            else{//temp->val >= x
                th->next=temp;
                temp=temp->next;
                th=th->next;
            }
        }
        tl->next=hi->next;
        th->next=NULL;
        
        
        return lo->next;
    }
};
