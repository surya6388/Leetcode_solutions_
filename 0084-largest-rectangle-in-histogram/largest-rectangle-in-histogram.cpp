// 0084. Largest Rectangle in Histogram [Hard]
// https://leetcode.com/problems/largest-rectangle-in-histogram/
//
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
//
//
//
// Example 1:
//
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
//
// Example 2:
//
// Input: heights = [2,4]
// Output: 4
//
//
//
// Constraints:
//
// 	- 1 <= heights.length <= 105
//
// 	- 0 <= heights[i] <= 104

// --- First accepted solution (2025-07-02) ---

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

    // Step:1-> next smallest element's index array
    vector<int> nsi(n);
    stack<int> st ;
    // storing index of (last + 1) index when there is no such element possible in array
    nsi[n-1]=n; 
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.size()==0) nsi[i]=n;
        else nsi[i]=st.top();
        st.push(i);
    }
 
    // Step:2-> previous smallest element's index array   
    vector<int> psi(n);
    stack<int> gt ;
    psi[0]=-1;
    gt.push(0);
    for(int i=1;i<n;i++){
        while(gt.size()>0 && arr[gt.top()] >= arr[i]){
            gt.pop();
        }
        if(gt.size()==0) psi[i]=-1;
        else psi[i]=gt.top();
        gt.push(i);
    } 
    //Step:3-> 
    int maxArea=0;
    for(int i=0;i<n;i++){
        int area= arr[i]  * (nsi[i]-psi[i]-1);// height[i] = arr[i] , breadth[i] = nsi[i]-ps[i]-1
    maxArea= max(maxArea,area);
    }
    return maxArea;

    }
};
