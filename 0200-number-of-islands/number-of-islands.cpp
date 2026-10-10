// 0200. Number of Islands [Medium]
// https://leetcode.com/problems/number-of-islands/
//
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//
//
// Example 1:
//
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
//
// Example 2:
//
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
//
//
//
// Constraints:
//
// 	- m == grid.length
//
// 	- n == grid[i].length
//
// 	- 1 <= m, n <= 300
//
// 	- grid[i][j] is '0' or '1'.

// --- First accepted solution (2026-08-22) ---

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int cols=grid[0].size();
        int cc=0;// stores number of connected components
        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='0') continue;// if it is a water body
                if(grid[i][j]=='-1') continue; // if already visited land mark it by -1
                else{// new unvisited land 
                    cc++;
                    grid[i][j]='0';// mrk visited
                    // BFS
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(q.size()>0){
                        auto curr = q.front();
                        q.pop();
                        int currRow=curr.first;
                        int currCol = curr.second;
                        //up
                        if(currRow-1>=0 && grid[currRow-1][currCol]=='1'){
                            q.push({currRow-1,currCol});
                            grid[currRow-1][currCol]='0';
                        }
                        //down
                        if(currRow+1 <row && grid[currRow+1][currCol]=='1'){
                            q.push({currRow+1,currCol});
                            grid[currRow+1][currCol]='0';
                        }
                        // left
                        if(currCol-1>=0 && grid[currRow][currCol-1]=='1'){
                            q.push({currRow,currCol-1});
                            grid[currRow][currCol-1]='0';
                        }
                        //right
                        if(currCol+1<cols && grid[currRow][currCol+1]=='1'){
                            q.push({currRow,currCol+1});
                            grid[currRow][currCol+1]='0';
                        }
                    }

                }
                
            }
        }
        return cc;
        
    }
};
