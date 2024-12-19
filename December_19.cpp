class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, maxi = 0;
        for(int i = 0;i<arr.size(); i++){
            maxi = max(maxi, arr[i]);
            ans += maxi==i;
        }
        return ans;
    }
};