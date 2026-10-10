// 0059. Spiral Matrix II [Medium]
// https://leetcode.com/problems/spiral-matrix-ii/
//
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
//
//
//
// Example 1:
//
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
//
// Example 2:
//
// Input: n = 1
// Output: [[1]]
//
//
//
// Constraints:
//
// 	- 1 <= n <= 20

// --- First accepted solution (2025-06-27) ---

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> arr(n,vector<int>(n));
    int minr=0;
    int minc=0;
    int maxr=n-1;
    int maxc=n-1;
    int count=1;
    while(minr<=maxr && minc<=maxc){
        for(int j=minc;j<=maxc;j++){// right
            arr[minr][j]=count++;
        }
        minr++;
        for(int i=minr;i<=maxr;i++){// down
            arr[i][maxc]=count++;
        }
        maxc--;
        for(int j=maxc;j>=minc;j--){// left
            arr[maxr][j]=count++;
        }
        maxr--;
        for(int i=maxr;i>=minr;i--){//up
            arr[i][minc]=count++;
        }
        minc++;
        if(minr > maxr || minc>maxc) break;
    }
    return arr;
        
    }
};
