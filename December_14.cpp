class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        deque<int> minDeque, maxDeque; 
        int left = 0; 
        long long count = 0; 

        for (int right = 0; right < n; ++right) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right])
                maxDeque.pop_back();
            maxDeque.push_back(right);

            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right])
                minDeque.pop_back();
            minDeque.push_back(right);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (maxDeque.front() == left) maxDeque.pop_front();
                if (minDeque.front() == left) minDeque.pop_front();
                ++left; 
            }

            count += (right - left + 1);
        }

        return count;
    }
};