// 0138. Copy List with Random Pointer [Medium]
// https://leetcode.com/problems/copy-list-with-random-pointer/
//
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
//
// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
//
// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
//
// Return the head of the copied linked list.
//
// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
//
// 	- val: an integer representing Node.val
//
// 	- random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
//
// Your code will only be given the head of the original linked list.
//
//
//
// Example 1:
//
// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
//
// Example 2:
//
// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
//
// Example 3:
//
// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]
//
//
//
// Constraints:
//
// 	- 0 <= n <= 1000
//
// 	- -104 <= Node.val <= 104
//
// 	- Node.random is null or is pointing to some node in the linked list.

// --- First accepted solution (2025-06-30) ---

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
// step 1: Create a deep copy (without assigning random pointer).
    Node* copyRandomList(Node* head) {
        Node* dummy=new Node(0);
        Node* tempc=dummy;
        Node* temp=head;
        while(temp){
            Node* a = new Node(temp->val); 
            tempc->next = a;
            tempc=tempc->next;
            temp=temp->next;
        }

    // step 2: Create alternate connections(merge) between original and deep copy(without assigning random pointer)
    Node* duplicate=dummy->next;
    Node* a = head;//  original
    Node* b = duplicate; //deep copy
    dummy = new Node(-1);
    Node* tempd=dummy;
    while(a!= NULL && b != NULL){
        tempd->next=a;
        a=a->next;
        tempd=tempd->next;
        tempd->next=b;
        b=b->next;
        tempd=tempd->next;
    }
    dummy=dummy->next;
    // till now a LL is obtained with each element repeated and randomly connected (in case of original wala but we want these connections in duplicate)

    // step 3: Assigning random pointer of duplicate 
    // observe : t2 ->random = t1->random->next   : t1->original,t2->duplicate of formed LL
    Node* t1 = dummy;// t1 points head of formed LL which is basically head of originalLL
    while(t1 != NULL){
        Node* t2=t1->next;// t2 will traverse in duplicate(deep copy) part
        if(t1->random !=NULL) t2->random=t1->random->next;
        t1=t1->next->next;// t1 will traverse in original part
    }
    
    // step 4: removing the connection(separating original and duplicate)
    Node* d1=new Node(-1);
    Node* d2= new Node(0);
    t1=d1;
    Node* t2=d2;
    Node* t =dummy;// jispe LL pe traverse krna hai
    while(t){
        t1->next=t;
        t=t->next;
        t1=t1->next;
        t2->next=t;
        t=t->next;
        t2=t2->next;
    }
    // to break both
    t1->next=NULL;
    t2->next=NULL;

    d1=d1->next;// original LL with random connections
    d2=d2->next;// deep copy LL with random connections


    return d2;
    }
};
