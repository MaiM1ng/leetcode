class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, need;
        int valid = 0;
        int left = 0;
        int right = 0;
        int start;
        int len = INT_MAX;

        for (char c : t) {
            need[c]++;
        }

        while (right < s.size()) {
            char c = s[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }
                char c = s[left];
                left++;

                if (need.count(c)) {
                    if (window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
