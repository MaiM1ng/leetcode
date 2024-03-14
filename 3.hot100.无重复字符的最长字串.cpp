class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> window;
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            
            while (window[c] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
