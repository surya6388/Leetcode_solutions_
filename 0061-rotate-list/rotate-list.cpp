// 0061. Rotate List [Medium]
// https://leetcode.com/problems/rotate-list/
//
// Given the head of a linked list, rotate the list to the right by k places.
//
//
//
// Example 1:
//
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
//
// Example 2:
//
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
//
//
//
// Constraints:
//
// 	- The number of nodes in the list is in the range [0, 500].
//
// 	- -100 <= Node.val <= 100
//
// 	- 0 <= k <= 2 * 109

// --- First accepted solution (2025-06-27) ---


class Solution {
public:
// keep 3 pointer head , tail, and temp at (n-k-1)th index ; tail->next = head , head=temp->next and temp->next=NULL
    ListNode* rotateRight(ListNode* head, int k) {
        // calculating length
        ListNode* temp=head;
        ListNode* tail;
        int n=0;
        while(temp != NULL){
            n++;
            tail=temp;
            temp=temp->next;
        }
        if(n==0 || n==1) return head;
        temp=head;
        if (k>=n) k=k%n;
        for(int i=1;i<=n-k-1;i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;

        
        return head;
    }
};
