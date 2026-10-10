// 0542. 01 Matrix [Medium]
// https://leetcode.com/problems/01-matrix/
//
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//
// The distance between two cells sharing a common edge is 1.
//
//
//
// Example 1:
//
// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
//
// Example 2:
//
// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
//
//
//
// Constraints:
//
// 	- m == mat.length
//
// 	- n == mat[i].length
//
// 	- 1 <= m, n <= 104
//
// 	- 1 <= m * n <= 104
//
// 	- mat[i][j] is either 0 or 1.
//
// 	- There is at least one 0 in mat.
//
//
//
// Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

// --- First accepted solution (2026-08-09) ---

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        // Step 1: push all 0s into queue
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        // directions (up, down, left, right)
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        // Step 2: BFS
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto d : dir){
                int nx = x + d.first;
                int ny = y + d.second;
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    }
};
