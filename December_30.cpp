class Solution {
int MOD = 1e9+7;
private:
    int f(int& low, int& high, int& zero, int& one,int length, vector<int>&dp ){
        if(length>high)return 0;
        if(dp[length]!=-1)return dp[length];
        int ways = 0;
        if(length>=low)ways++;
        ways = (ways + f(low, high, zero, one, length + zero, dp) + f(low, high, zero, one, length + one, dp))%MOD;
        return dp[length] = ways;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1, -1);
        return f(low, high, zero, one, 0, dp);
    }
};