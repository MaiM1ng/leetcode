class Solution {
public:
    vector<vector<string>> res;
    vector<bool> used;

    bool isValid(int row, int col, vector<string>& track) {
        int r = row;
        int c = col;
        int n = used.size();

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

    void dfs(int n, vector<string>& track, int level, int lastSel) {
        if (level >= n) {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!used[i] && isValid(level, i, track)) {
                used[i] = true;
                track[level][i] = 'Q';
                dfs(n, track, level + 1, i);
                track[level][i] = '.';
                used[i] = false;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        used = vector<bool>(n, false);
        vector<string> track(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                track[i] += '.';
            }
        }

        for (int i = 0; i < n; i++) {
            used[i] = true;
            track[0][i] = 'Q';
            dfs(n, track, 1, i);
            track[0][i] = '.';
            used[i] = false;
        }

        return res;
    }
};
