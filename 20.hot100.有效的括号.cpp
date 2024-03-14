class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                sk.push(c);
            } else {
                if (sk.size() == 0) return false;
                char top = sk.top();
                sk.pop();
                if (c == ')') {
                    if (top != '(') return false;
                } else if (c == '}') {
                    if (top != '{') return false;
                } else if (c == ']') {
                    if (top != '[') return false;
                }
            }
        }

        return sk.empty();
    }
};
