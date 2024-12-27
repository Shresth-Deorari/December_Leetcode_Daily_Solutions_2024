class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        int ans = INT_MIN, curr = nums[0];
        for(int i = 1;i<nums .size(); i++){
            ans = max(ans, curr + nums[i]-i);
            curr = max(curr, nums[i]+i);
        }
        return ans;
    }
};