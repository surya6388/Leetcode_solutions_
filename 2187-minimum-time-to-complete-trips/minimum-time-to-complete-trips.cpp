// 2187. Minimum Time to Complete Trips [Medium]
// https://leetcode.com/problems/minimum-time-to-complete-trips/
//
// You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.
//
// Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.
//
// You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.
//
//
//
// Example 1:
//
// Input: time = [1,2,3], totalTrips = 5
// Output: 3
// Explanation:
// - At time t = 1, the number of trips completed by each bus are [1,0,0].
//   The total number of trips completed is 1 + 0 + 0 = 1.
// - At time t = 2, the number of trips completed by each bus are [2,1,0].
//   The total number of trips completed is 2 + 1 + 0 = 3.
// - At time t = 3, the number of trips completed by each bus are [3,1,1].
//   The total number of trips completed is 3 + 1 + 1 = 5.
// So the minimum time needed for all buses to complete at least 5 trips is 3.
//
// Example 2:
//
// Input: time = [2], totalTrips = 1
// Output: 2
// Explanation:
// There is only one bus, and it will complete its first trip at t = 2.
// So the minimum time needed to complete 1 trip is 2.
//
//
//
// Constraints:
//
// 	- 1 <= time.length <= 105
//
// 	- 1 <= time[i], totalTrips <= 107

// --- First accepted solution (2025-05-31) ---

class Solution {
public:
    bool check(long long mid,vector<int>& time, int totalTrips){
        long long trips=0; // number of trips in each hour
        int n=time.size();
        for(int i=0;i<n;i++){
             trips += mid/(long long)time[i];
        }
        if(trips < (long long) totalTrips) return false;
        else return true;

    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        int max=0;
        for(int i=0;i<n;i++){
            if(time[i]>max){
                max=time[i];
            }
        }
        long long l=1;
        long long h= (long long)max * (long long)totalTrips;
        long long ans=-1;
        while(l<=h){
            long long mid= l + (h-l)/2;
            if(check(mid,time,totalTrips)==true){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans; 

        
    }
};
