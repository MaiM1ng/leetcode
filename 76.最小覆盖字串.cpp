class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> window, need;
        int valid = 0;
        string ans;
        int minLen = INT_MAX;
        int start = 0;
        
        for (char c: t) {
            need[c]++;
        }

        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.find(c) != need.end()) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                if (right - left < minLen) {
                    minLen = right - left;
                    // ans = s.substr(left, minLen);  //超时
                    start = left;
                }
                char c = s[left];
                left++;
                if (need.find(c) != need.end()) {
                    if (window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
