// 0056. Merge Intervals [Medium]
// https://leetcode.com/problems/merge-intervals/
//
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
//
//
//
// Example 1:
//
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
//
// Example 2:
//
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
// Example 3:
//
// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.
//
//
//
// Constraints:
//
// 	- 1 <= intervals.length <= 104
//
// 	- intervals[i].length == 2
//
// 	- 0 <= starti <= endi <= 104

// --- First accepted solution (2025-07-22) ---

bool cmp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> result;
        sort(v.begin(),v.end(),cmp);// sorting according to end
        int n=v.size();
        result.push_back(v[n-1]);
        for(int i=n-2;i>=0;i--){
            vector<int> &lastInterval = result[result.size()-1];
            vector<int> curr = v[i];
            if(curr[1] >= lastInterval[0]){// if curr.end >= last.start => overlapping
                lastInterval[0] = min(lastInterval[0],curr[0]);
                lastInterval[1] = max(lastInterval[1],curr[1]);
            }
            else{
                result.push_back(v[i]);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
