class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        vector<int>result = prices;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && prices[st.top()]>prices[i]){
                st.pop();
            }
            if(!st.empty())result[i] -= prices[st.top()];
            st.push(i);
        }
        return result;
    }
};