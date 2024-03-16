class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)  {
            return s;
        }
        vector<vector<char> > lst(numRows);
        string ans;
        bool isAdd = true;
        int cur = 0;

        for (int i = 0; i < s.size(); i++) {
            lst[cur].push_back(s[i]);
            if (cur == 0) {
                isAdd = true;
            } else if (cur == numRows - 1) {
                isAdd = false;
            }

            if (isAdd) {
                cur++;
            } else {
                cur--;
            }
        }

        for (int i = 0; i < numRows; i++) {
            for (char each: lst[i]) {
                ans += each;
            }
        }

        return ans;
    }
};
