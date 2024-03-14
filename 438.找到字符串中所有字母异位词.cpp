class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window, need;
        int left = 0;
        int right = 0;
        int valid = 0;
        vector<int> ans;

        for (char c : p) {
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
                if ((right - left) == p.size()) {
                    ans.push_back(left);
                }
                char c = s[left++];
                if (need.count(c)) {
                    if (window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }

        return ans;
    }
};
