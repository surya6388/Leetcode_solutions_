// 1034. Coloring A Border [Medium]
// https://leetcode.com/problems/coloring-a-border/
//
// You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
//
// Two squares are called adjacent if they are next to each other in any of the 4 directions.
//
// Two squares belong to the same connected component if they have the same color and they are adjacent.
//
// The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).
//
// You should color the border of the connected component that contains the square grid[row][col] with color.
//
// Return the final grid.
//
//
//
// Example 1:
//
// Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
// Output: [[3,3],[3,2]]
//
// Example 2:
//
// Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
// Output: [[1,3,3],[2,3,3]]
//
// Example 3:
//
// Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
// Output: [[2,2,2],[2,1,2],[2,2,2]]
//
//
//
// Constraints:
//
// 	- m == grid.length
//
// 	- n == grid[i].length
//
// 	- 1 <= m, n <= 50
//
// 	- 1 <= grid[i][j], color <= 1000
//
// 	- 0 <= row < m
//
// 	- 0 <= col < n

// --- First accepted solution (2026-08-21) ---

class Solution {
public:
    vector<pair<int,int>> internal;

    void dfs(vector<vector<int>>& grid, int r, int c, int originalColor){
        int m = grid.size();
        int n = grid[0].size();

        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != originalColor)
            return;
        // mark visited
        grid[r][c] = -1;
        dfs(grid, r+1, c, originalColor);
        dfs(grid, r-1, c, originalColor);
        dfs(grid, r, c+1, originalColor);
        dfs(grid, r, c-1, originalColor);

        // check internal
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        bool isInternal = true;

        for(auto d : dirs){
            int nr = r + d.first;
            int nc = c + d.second;

            if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] != -1){
                isInternal = false;
                break;
            }
        }

        if(isInternal){
            internal.push_back({r,c});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int originalColor = grid[row][col];
        if(originalColor == color) return grid;

        dfs(grid, row, col, originalColor);

        // color everything first
        for(auto &rowVec : grid){
            for(auto &cell : rowVec){
                if(cell == -1) cell = color;
            }
        }

        // revert internal cells
        for(auto &p : internal){
            grid[p.first][p.second] = originalColor;
        }

        return grid;
    }
};
