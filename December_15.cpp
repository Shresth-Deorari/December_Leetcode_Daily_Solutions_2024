class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto i : classes){
            double ratio = ((i[0]+1)/double(i[1]+1)) - i[0]/double(i[1]);
            pq.push({ratio,{i[1],i[0]}});
        }
        while(extraStudents--){
            int total = pq.top().second.first;
            int pass = pq.top().second.second;
            pq.pop();
            pass++; total++;
            double ratio = ((pass+1)/double(total+1)) - pass/double(total);
            pq.push({ratio,{total,pass}});
        }
        double ans = 0;
        while(!pq.empty()){
            double ratio = double(pq.top().second.second)/pq.top().second.first; 
            ans += ratio;
            pq.pop();
        }
        ans = ans/classes.size();
        return ans;
    }
};