class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<bool>ans(m, false);
        vector<int>prefix(n,0);
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + ((nums[i]&1) == (nums[i-1]&1));
        }
        for(int i = 0;i<m; i++){
            int low = queries[i][0];
            int high = queries[i][1];
            int diff = prefix[high] - prefix[low];
            ans[i] = (diff==0);
        }
        return ans;
    }
};