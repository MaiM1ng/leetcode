class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int slow = 0;
        int fast;

        for (fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' ') {
                if (slow != 0) {
                    s[slow++] = ' ';
                }
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        s.resize(slow);
        reverse(s.begin(), s.end());

        int start = 0;
        int nextBlk = 0;
        for (int i = 0; i <= s.size(); i++) {
            start = nextBlk;
            if (s[i] == ' ' || i == s.size()) {
                nextBlk = i;
                reverse(s.begin() + start, s.begin() + nextBlk);
                nextBlk++;
            }
        }

        return s;
    }
};
