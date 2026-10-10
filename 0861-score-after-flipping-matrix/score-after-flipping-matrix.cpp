// 0861. Score After Flipping Matrix [Medium]
// https://leetcode.com/problems/score-after-flipping-matrix/
//
// You are given an m x n binary matrix grid.
//
// A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
//
// Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
//
// Return the highest possible score after making any number of moves (including zero moves).
//
//
//
// Example 1:
//
// Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//
// Example 2:
//
// Input: grid = [[0]]
// Output: 1
//
//
//
// Constraints:
//
// 	- m == grid.length
//
// 	- n == grid[i].length
//
// 	- 1 <= m, n <= 20
//
// 	- grid[i][j] is either 0 or 1.

// --- First accepted solution (2025-04-03) ---

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int m=grid.size();// rows
    int n=grid[0].size();
    // 1) making 1st column all 1s by flipping
    for(int i=0;i<m;i++){
        if(grid[i][0]==0){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }
        }    
    }    
    // 2) flip the columns where noz>no1
    for(int j=0;j<n;j++){
        int noz=0;
        int no1=0;
        for(int i=0;i<m;i++){
            if(grid[i][j]==0) noz++;
            else no1++;
        }
        if(noz>no1){
            for(int i=0;i<m;i++){
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;

            }
        }
    }
    // 3) storing sum
    int sum=0;
    for(int i=0;i<m;i++){
        int x=1;
        for(int j=n-1;j>=0;j--){
            sum+=grid[i][j]*x;
            x*=2;
        }

    }
    return sum;

        
    }
};
