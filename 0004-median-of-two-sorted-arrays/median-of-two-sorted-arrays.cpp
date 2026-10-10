// 0004. Median of Two Sorted Arrays [Hard]
// https://leetcode.com/problems/median-of-two-sorted-arrays/
//
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//
// The overall run time complexity should be O(log (m+n)).
//
//
//
// Example 1:
//
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
//
// Example 2:
//
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
//
//
//
// Constraints:
//
// 	- nums1.length == m
//
// 	- nums2.length == n
//
// 	- 0 <= m <= 1000
//
// 	- 0 <= n <= 1000
//
// 	- 1 <= m + n <= 2000
//
// 	- -106 <= nums1[i], nums2[i] <= 106

// --- First accepted solution (2025-08-22) ---

class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int m= v1.size();
        int n=v2.size();
        vector<int> v3(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(v1[i] > v2[j]){
                v3[k++]=v2[j++];
            }
            else{
                v3[k++]=v1[i++];
            }
        }
        if(i==m){
            while(j < n){
                v3[k++]=v2[j++];
            }
        }
        if(j==n){ 
            while(i < m){
                v3[k++]=v1[i++];
            }
        }
        int x = v3.size();
        if(x %2 != 0) return v3[x/2];
        else{
            double med = (v3[x/2] + v3[x/2 - 1])/2.0;
            return med;
        }
       
        
    }
};
