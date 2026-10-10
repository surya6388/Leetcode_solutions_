// 1584. Min Cost to Connect All Points [Medium]
// https://leetcode.com/problems/min-cost-to-connect-all-points/
//
// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//
// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
//
// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
//
//
//
// Example 1:
//
// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation:
//
// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
//
// Example 2:
//
// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18
//
//
//
// Constraints:
//
// 	- 1 <= points.length <= 1000
//
// 	- -106 <= xi, yi <= 106
//
// 	- All pairs (xi, yi) are distinct.

// --- First accepted solution (2026-08-31) ---

class Solution {
public:
    int find(vector<int> &parent, int x){
        return parent[x] = (parent[x] == x)?x: find(parent, parent[x]);
    }

    void Union(vector<int> &parent, vector<int> &rank, int a, int b){
        a = find(parent, a);
        b = find(parent, b);
        if(a == b) return;
        if(rank[a] >= rank[b]){
            parent[b] = a;
            rank[a]++;
        } 
        else {
            parent[a] = b;
            rank[b]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        //  Step 1: Create edge list
        vector<vector<int>> edges;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({d, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(n), rank(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
        int ans = 0;
        int edgeCount = 0;
        for(auto &e : edges){
            int wt = e[0];
            int src = e[1];
            int dest = e[2];
            if(find(parent, src) != find(parent, dest)){
                Union(parent, rank, src, dest);
                ans += wt;
                edgeCount++;
                if(edgeCount == n-1) break;
            }
        }

        return ans;
    }
};
