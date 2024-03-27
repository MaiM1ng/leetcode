class Solution {
public:
    int res;
    vector<bool> used;

    bool isValid(int row, int col, vector<string>& track) {
        int n = used.size();

        int r = row;
        int c = col;

        while (r >= 0 && c >= 0) {
            if (track[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        r = row;
        c = col;

        while (r >= 0 && c < n) {
            if (track[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }

        return true;
    }

    void dfs(int n, vector<string>& track, int level) {
        if (level >= n) {
            res++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!used[i] && isValid(level, i, track)) {
                used[i] = true;
                track[level][i] = 'Q';
                dfs(n, track, level + 1);
                track[level][i] = '.';
                used[i] = false;                
            }
        }

    }

    int totalNQueens(int n) {
        used = vector<bool>(n, false);
        res = 0;
        vector<string> track = vector<string>(n, string(n, '.'));

        for (int i = 0; i < n; i++) {
            used[i] = true;
            track[0][i] = 'Q';
            dfs(n, track, 1);
            track[0][i] = '.';
            used[i] = false;
        } 

        return res;
    }
};
