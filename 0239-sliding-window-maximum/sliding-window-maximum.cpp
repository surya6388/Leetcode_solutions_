// 0239. Sliding Window Maximum [Hard]
// https://leetcode.com/problems/sliding-window-maximum/
//
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//
// Return the max sliding window.
//
//
//
// Example 1:
//
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
// Example 2:
//
// Input: nums = [1], k = 1
// Output: [1]
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 105
//
// 	- -104 <= nums[i] <= 104
//
// 	- 1 <= k <= nums.length

// --- First accepted solution (2025-07-03) ---

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(); 
        //next greater elemnet's index
        vector<int> ngi(n);
        stack<int> st;
        ngi[n-1]=n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.size()==0) ngi[i]=n;
            else ngi[i]=st.top();
            st.push(i);
        }

        vector<int> ans;
        for(int i=0;i<n-k+1;i++){
            int mx=nums[i];// starting of window
            int j=i;
            while(j < i+k){// if nge is inside window
                mx=nums[j];
                j=ngi[j];// go to next greater
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
