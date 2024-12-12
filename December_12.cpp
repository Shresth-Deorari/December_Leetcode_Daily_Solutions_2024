class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto i : gifts)pq.push(i);
        while(k-- && !pq.empty()){
            int curr = pq.top();
            pq.pop();
            pq.push(floor(sqrt(curr))); 
        }
        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};