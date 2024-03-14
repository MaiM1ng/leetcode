class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window, need;
        int valid = 0;
        int left = 0;
        int right = 0;
        
        for (char c : s1) {
            need[c]++;
        }

        while (right < s2.size()) {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                if ((right - left) == s1.size()) {
                    printf("%d\n", (right - left));
                    return true;
                }

                char c = s2[left];
                left++;

                if (need.count(c)) {
                    if (need[c] == window[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }

        return false;
    }
};
