// 0054. Spiral Matrix [Medium]
// https://leetcode.com/problems/spiral-matrix/
//
// Given an m x n matrix, return all elements of the matrix in spiral order.
//
//
//
// Example 1:
//
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
//
// Example 2:
//
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//
//
//
// Constraints:
//
// 	- m == matrix.length
//
// 	- n == matrix[i].length
//
// 	- 1 <= m, n <= 10
//
// 	- -100 <= matrix[i][j] <= 100

// --- First accepted solution (2025-04-01) ---

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int minr=0;
        int minc=0;
        int maxr=m-1;
        int maxc=n-1;
        int tne=m*n;
        int count=0;
        vector<int> v;
        while(minr<=maxr && minc<=maxc){
            for(int j=minc;j<=maxc && count<tne;j++){// right
                v.push_back(matrix[minr][j]);
                count++;
            }
            minr++;
            for(int i=minr;i<=maxr && count<tne;i++){// down
                v.push_back(matrix[i][maxc]);
                count++;
            }
            maxc--;
            for(int j=maxc;j>=minc && count<tne;j--){// left
                v.push_back(matrix[maxr][j]);
                count++;
            }
            maxr--;
            for(int i=maxr;i>=minr && count<tne;i--){//up
                v.push_back(matrix[i][minc]);
                count++;
            }
            minc++;
        }
        return v;

        
    }
};
