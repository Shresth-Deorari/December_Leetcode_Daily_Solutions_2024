class Solution {
    int MOD = 1e9 + 7;

public:
    int numWays(vector<string>& words, string target) {
        int m = target.size();
        int n = words[0].size();
        
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (const string& word : words) {
            for (int i = 0; i < n; i++) {
                freq[i][word[i] - 'a']++;
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        function<int(int, int)> f = [&](int i, int j) {
            if (j == m) return 1;
            if (i == n) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            int notTaken = f(i + 1, j) % MOD;
            int taken = 0;
            if (freq[i][target[j] - 'a'] > 0) {
                taken = (1LL * freq[i][target[j] - 'a'] * f(i + 1, j + 1)) % MOD;
            }
            return dp[i][j] = (notTaken + taken) % MOD;
        };

        return f(0, 0);
    }
};
