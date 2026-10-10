// 0875. Koko Eating Bananas [Medium]
// https://leetcode.com/problems/koko-eating-bananas/
//
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
//
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
//
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
//
// Return the minimum integer k such that she can eat all the bananas within h hours.
//
//
//
// Example 1:
//
// Input: piles = [3,6,7,11], h = 8
// Output: 4
//
// Example 2:
//
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
//
// Example 3:
//
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
//
//
//
// Constraints:
//
// 	- 1 <= piles.length <= 104
//
// 	- piles.length <= h <= 109
//
// 	- 1 <= piles[i] <= 109

// --- First accepted solution (2025-05-31) ---

class Solution {
public:
    bool check(int mid,vector<int>& piles, int h){
        int count=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
             if(count > h) return false;
            if(mid >= piles[i]) count++; // mid is representing current speed
            else if(piles[i] % mid  ==0) count+=piles[i]/mid; 
            else  count+= (piles[i]/mid) +1; // if piles[i] is greater than current speed(mid) then piles by mid +1 gives number of days
        }
        if(count > h) return false;
        else return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) { // h is not high it is number of days given
        int n=piles.size();
        int max=-1;
        for(int i=0;i<n;i++){
            if(piles[i]>max){
                max=piles[i];
            }
        }
        int l=1;
        int high=max;// max in array
        int ans=-1;
        while(l<=high){
            int mid=l + (high-l)/2;// current speed of eating banana
            if(check(mid,piles,h)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;

        
    }
};
