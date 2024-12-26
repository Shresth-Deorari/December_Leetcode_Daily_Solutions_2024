class Solution {
int f(vector<int>&nums, int target, int i, int sum, vector<vector<int>>&dp){
    if(i==nums.size() && sum==target)return 1;
    if(i==nums.size())return 0;
    if(dp[i][sum + 1000]!=-1)return dp[i][sum + 1000];
    int add = 0, sub = 0;
    add = f(nums, target, i+1, sum + nums[i], dp);
    sub = f(nums, target, i+1, sum - nums[i], dp);
    return dp[i][sum+ 1000] = add + sub;
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(2001 , -1));
        return f(nums, target, 0, 0, dp);
    }
};