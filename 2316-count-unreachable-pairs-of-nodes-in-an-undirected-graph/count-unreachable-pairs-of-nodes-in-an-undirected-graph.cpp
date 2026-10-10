// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph [Medium]
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
//
// You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
//
// Return the number of pairs of different nodes that are unreachable from each other.
//
//
//
// Example 1:
//
// Input: n = 3, edges = [[0,1],[0,2],[1,2]]
// Output: 0
// Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
//
// Example 2:
//
// Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
// Output: 14
// Explanation: There are 14 pairs of nodes that are unreachable from each other:
// [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
// Therefore, we return 14.
//
//
//
// Constraints:
//
// 	- 1 <= n <= 105
//
// 	- 0 <= edges.length <= 2 * 105
//
// 	- edges[i].length == 2
//
// 	- 0 <= ai, bi < n
//
// 	- ai != bi
//
// 	- There are no repeated edges.

// --- First accepted solution (2026-08-30) ---

class Solution {
public:
    // DFS returns the size of the current connected component
    long long dfs(int curr, vector<int>& visited, vector<vector<int>>& adj) {
        visited[curr] = 1;
        long long size = 1; // Count the current node
        for (int neighbor : adj[curr]) {
            if (visited[neighbor] == 0) {
                size += dfs(neighbor, visited, adj); // Add sizes of all connected nodes
            }
        }
        return size;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        // 1. Build the graph
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        long long totalPairs = 0;
        long long nodesVisitedSoFar = 0;
        
        // 2. Find components and calculate pairs
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                // Get the size of the current component
                long long currentComponentSize = dfs(i, visited, adj);
                // 3. The math trick: New nodes * Old nodes
                totalPairs += (currentComponentSize * nodesVisitedSoFar);
                // Update the total nodes we've seen
                nodesVisitedSoFar += currentComponentSize;
            }
        }
        
        return totalPairs;
    }
};
