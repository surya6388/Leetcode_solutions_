// 0155. Min Stack [Medium]
// https://leetcode.com/problems/min-stack/
//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
// Implement the MinStack class:
//
// 	- MinStack() initializes the stack object.
//
// 	- void push(int value) pushes the element value onto the stack.
//
// 	- void pop() removes the element on the top of the stack.
//
// 	- int top() gets the top element of the stack.
//
// 	- int getMin() retrieves the minimum element in the stack.
//
// You must implement a solution with O(1) time complexity for each function.
//
//
//
// Example 1:
//
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
//
// Output
// [null,null,null,null,-3,null,0,-2]
//
// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
//
//
//
// Constraints:
//
// 	- -231 <= val <= 231 - 1
//
// 	- Methods pop, top and getMin operations will always be called on non-empty stacks.
//
// 	- At most 3 * 104 calls will be made to push, pop, top, and getMin.

// --- First accepted solution (2025-07-03) ---

class MinStack {
public:
    stack<int> st;
    stack<int> helper;
    MinStack() {// constructor
        
    }
    
    void push(int val) {//O(1)
        st.push(val);
        if(helper.size()==0 || val < helper.top() ) helper.push(val);
        else  helper.push(helper.top());
    }
    
    void pop() {//O(1)
        st.pop();
        helper.pop();
        
    }
    
    int top() {//O(1)
        return st.top();
        
    }
    
    int getMin() { 
        // M2: using extra stack(make 2 empty stacks st and gt; if stack is empty then fill the upcoming element in both else check and fill the min while filling in gt  )
        
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
