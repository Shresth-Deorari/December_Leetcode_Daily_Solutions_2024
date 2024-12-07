class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            int count = 0;
            for(auto i : nums){
                count += ceil((i+mid-1)/mid);
            }
            if(count-nums.size() <= maxOperations){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};