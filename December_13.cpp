class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        unordered_set<int>st;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(st.size()!=nums.size()){
            int curr = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            if(st.count(ind))continue;
            sum += curr;
            st.insert(ind);
            if(ind-1>=0)st.insert(ind-1);
            if(ind+1<n)st.insert(ind+1);            
        }
        return sum;
    }
};