// 0633. Sum of Square Numbers [Medium]
// https://leetcode.com/problems/sum-of-square-numbers/
//
// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
//
//
//
// Example 1:
//
// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
//
// Example 2:
//
// Input: c = 3
// Output: false
//
//
//
// Constraints:
//
// 	- 0 <= c <= 231 - 1

// --- First accepted solution (2025-05-31) ---

class Solution {
public:
    bool isperfectsquare(int n){
        int root=sqrt(n);
        if(root * root ==n ) return true; 
        else return false;

    }
    bool judgeSquareSum(int c) {
        int x=0;
        int y=c;
        while(x <= y){
            if(isperfectsquare(x) && isperfectsquare(y)) // to check whether x and y are perfect square
                return true;
                else if(!isperfectsquare(y)){ 
                    y=(int)sqrt(y) * (int)sqrt(y);
                    x=c-y;

                }
                else{// x is not perfect square 
                 x=((int)sqrt(x)+1) * ((int)sqrt(x)+1);
                 y=c-x;


                }
               
            }
            return false;
        
        
    }
};
