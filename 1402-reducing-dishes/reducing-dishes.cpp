// 1402. Reducing Dishes [Hard]
// https://leetcode.com/problems/reducing-dishes/
//
// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
//
// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
//
// Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.
//
// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
//
//
//
// Example 1:
//
// Input: satisfaction = [-1,-8,0,5,-9]
// Output: 14
// Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
// Each dish is prepared in one unit of time.
//
// Example 2:
//
// Input: satisfaction = [4,3,2]
// Output: 20
// Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
//
// Example 3:
//
// Input: satisfaction = [-1,-4,-5]
// Output: 0
// Explanation: People do not like the dishes. No dish is prepared.
//
//
//
// Constraints:
//
// 	- n == satisfaction.length
//
// 	- 1 <= n <= 500
//
// 	- -1000 <= satisfaction[i] <= 1000

// --- First accepted solution (2025-06-14) ---

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
    int n=satisfaction.size();
    // 1:sorting
    sort(satisfaction.begin(),satisfaction.end());
    // 2:making suffix sum array
    vector<int> sufsum(n);
    sufsum[n-1]=satisfaction[n-1];
    for(int i=n-2;i>=0;i--){
        sufsum[i]=sufsum[i+1] + satisfaction[i]; 
    }
    // 3:finding pivot index from where to start 
    int idx=-1;
    for(int i=0;i<n;i++){
        if(sufsum[i]>=0){
            idx=i;
            break; 
        }
    }
    if(idx==-1) return 0;// all elements are negative so return 0
    //4: Max sum of like time coefficient
    int x=1;
    int maxsum=0;
    for(int i=idx;i<n;i++){
        maxsum = maxsum + (satisfaction[i] * x);
        x++;
    }
    return maxsum;
    
        
    }
};
