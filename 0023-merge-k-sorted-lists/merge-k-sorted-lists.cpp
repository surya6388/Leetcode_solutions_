// 0023. Merge k Sorted Lists [Hard]
// https://leetcode.com/problems/merge-k-sorted-lists/
//
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//
// Merge all the linked-lists into one sorted linked-list and return it.
//
//
//
// Example 1:
//
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6
//
// Example 2:
//
// Input: lists = []
// Output: []
//
// Example 3:
//
// Input: lists = [[]]
// Output: []
//
//
//
// Constraints:
//
// 	- k == lists.length
//
// 	- 0 <= k <= 104
//
// 	- 0 <= lists[i].length <= 500
//
// 	- -104 <= lists[i][j] <= 104
//
// 	- lists[i] is sorted in ascending order.
//
// 	- The sum of lists[i].length will not exceed 104.

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
    if(a == NULL){
        temp->next=b;
    }
    else{
        temp->next=a;
    }
    return c->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr ) {
        if(arr.size()==0) return NULL;
        while(arr.size() > 1){
            // last ke do element nikal kr dono ko merge krke pushback kr do
            ListNode* a= arr[(arr.size( )-1)];
            arr.pop_back();
            ListNode* b =arr[(arr.size( )-1)];
            arr.pop_back();
            ListNode*  c =mergeTwoLists(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};
