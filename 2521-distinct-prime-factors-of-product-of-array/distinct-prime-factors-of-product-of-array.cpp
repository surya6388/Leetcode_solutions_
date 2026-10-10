// 2521. Distinct Prime Factors of Product of Array [Medium]
// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/
//
// Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.
//
// Note that:
//
// 	- A number greater than 1 is called prime if it is divisible by only 1 and itself.
//
// 	- An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.
//
//
//
// Example 1:
//
// Input: nums = [2,4,3,7,10,6]
// Output: 4
// Explanation:
// The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
// There are 4 distinct prime factors so we return 4.
//
// Example 2:
//
// Input: nums = [2,4,8,16]
// Output: 1
// Explanation:
// The product of all the elements in nums is: 2 * 4 * 8 * 16 = 1024 = 210.
// There is 1 distinct prime factor so we return 1.
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 104
//
// 	- 2 <= nums[i] <= 1000

// --- First accepted solution (2025-06-20) ---

class Solution {
public:
    void fillsieve(vector<bool> &sieve){
    int n=sieve.size()-1;
    for(int i=2;i<=sqrt(n);i++){
        for(int j=i*2;j<=n;j+=i){
            sieve[j]=0;
        }
    }
}
    int distinctPrimeFactors(vector<int>& nums) {
        int n=nums.size();
        int mx=-1;
        int count=0;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
        }
        vector<bool> sieve(mx+1,1);// 1 means prime and 0 means not prime
        if(mx+1 > 0) sieve[0]=0;
        if(mx+1 >1) sieve[1]=0;
        fillsieve(sieve);

        vector<int> prime;
        for(int i=2;i<=mx;i++){
            if(sieve[i]==1) prime.push_back(i);
        }
        vector<bool> taken(prime.size(),0);
        for(int i=0;i<nums.size();i++){
            int ele=nums[i];
            for(int j=0;j<taken.size();j++){
                if(prime[j]> ele) break;
                if(ele % prime[j]==0) taken[j]=1;
            }
        }
        for(int i=0;i<taken.size();i++){
            if(taken[i]==1) count++;

        }

        
              
        return count;
        
        
    }
};
