// 0119. Pascal's Triangle II [Easy]
// https://leetcode.com/problems/pascals-triangle-ii/
//
// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
//
//
//
// Example 1:
//
// Input: rowIndex = 3
// Output: [1,3,3,1]
//
// Example 2:
//
// Input: rowIndex = 0
// Output: [1]
//
// Example 3:
//
// Input: rowIndex = 1
// Output: [1,1]
//
//
//
// Constraints:
//
// 	- 0 <= rowIndex <= 33
//
//
//
// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

// --- First accepted solution (2025-08-27) ---

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> >v;
    for(int i=0;i<=rowIndex;i++){ // numrows ke equal utna vector banega aur v me store hoga
        vector<int> a(i+1);
        v.push_back(a);

    }
    // generation
    for(int i=0;i<=rowIndex;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i ){// first aur last column me 1
                v[i][j] = 1;
            }
            else{
                v[i][j] = v[i-1][j] + v[i-1][j-1];// jo chahiye wo uske (just uper wala + uper ke left wala)
            }

        }
    }
    return v[rowIndex];
   
      
      
    }
};
