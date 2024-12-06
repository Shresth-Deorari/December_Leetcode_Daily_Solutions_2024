class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st;
        for(auto i : banned){
            st.insert(i);
        }

        int sum = 0, ans = 0;
        for(int i = 1;i<=n;i++){
            if(st.count(i))continue;
            if(sum + i > maxSum)break;
            sum += i;
            ans++;
        }
        return ans;
    }
};