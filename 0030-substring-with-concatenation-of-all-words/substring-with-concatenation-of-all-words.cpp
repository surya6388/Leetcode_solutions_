// 0030. Substring with Concatenation of All Words [Hard]
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
//
// You are given a string s and an array of strings words. All the strings of words are of the same length.
//
// A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
//
// 	- For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
//
// Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
//
//
//
// Example 1:
//
// Input: s = "barfoothefoobarman", words = ["foo","bar"]
//
// Output: [0,9]
//
// Explanation:
//
// The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
//
// The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
//
// Example 2:
//
// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//
// Output: []
//
// Explanation:
//
// There is no concatenated substring.
//
// Example 3:
//
// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//
// Output: [6,9,12]
//
// Explanation:
//
// The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
//
// The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
//
// The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
//
//
//
// Constraints:
//
// 	- 1 <= s.length <= 104
//
// 	- 1 <= words.length <= 5000
//
// 	- 1 <= words[i].length <= 30
//
// 	- s and words[i] consist of lowercase English letters.

// --- First accepted solution (2026-08-10) ---

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        int n = s.size();
        int wordLen = words[0].size();
        int totalWords = words.size();
        int windowLen = wordLen * totalWords;

        unordered_map<string, int> freq;
        for (auto &w : words) freq[w]++;

        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int right = i; right + wordLen <= n; right += wordLen) {

                string word = s.substr(right, wordLen);

                if (freq.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > freq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == totalWords) {
                        result.push_back(left);
                    }

                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
};
