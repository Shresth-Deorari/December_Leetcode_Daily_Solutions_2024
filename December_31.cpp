class Solution {
private:
    int f(vector<int>& days, vector<int>& costs, int i, vector<int>& memo) {
        if (i >= days.size()) return 0;
        
        if (memo[i] != -1) return memo[i];
        
        int one = costs[0] + f(days, costs, i + 1, memo);
        
        int ind2 = i;
        while (ind2 < days.size() && days[ind2] < days[i] + 7) ind2++;
        int seven = costs[1] + f(days, costs, ind2, memo);
        
        ind2 = i;
        while (ind2 < days.size() && days[ind2] < days[i] + 30) ind2++;
        int thirty = costs[2] + f(days, costs, ind2, memo);
        
        return memo[i] = min({one, seven, thirty});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1);
        return f(days, costs, 0, memo);
    }
};
