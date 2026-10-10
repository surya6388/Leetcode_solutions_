// 0781. Rabbits in Forest [Medium]
// https://leetcode.com/problems/rabbits-in-forest/
//
// There is a forest with an unknown number of rabbits. We asked n rabbits "How many other rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
//
// Given the array answers, return the minimum number of rabbits that could be in the forest.
//
//
//
// Example 1:
//
// Input: answers = [1,1,2]
// Output: 5
// Explanation:
// The two rabbits that answered "1" could both be the same color, say red.
// The rabbit that answered "2" can't be red or the answers would be inconsistent.
// Say the rabbit that answered "2" was blue.
// Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
// The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
//
// Example 2:
//
// Input: answers = [10,10,10]
// Output: 11
//
//
//
// Constraints:
//
// 	- 1 <= answers.length <= 1000
//
// 	- 0 <= answers[i] < 1000

// --- First accepted solution (2025-07-22) ---

class Solution {
public:
    int numRabbits(vector<int>& arr) {
        unordered_map<int,int> m;
        int result = 0;
        for(int i=0;i< arr.size();i++){
            if(!m[arr[i]+1]){// if freq of key exceed start new group
                result += arr[i]+1;
                if(arr[i]==0) continue;
                m[arr[i]+1] = 1;

            }    
            else m[arr[i]+1]++; // if already exist then increase freq  
            int key = arr[i]+1;
            int  val = m[key]; 
            if(key==val){// we have found the rabbit of group 
            //now eliminate the group
            m.erase(key);

            }
        }
        return result;
    }
};
