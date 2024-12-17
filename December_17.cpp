class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>>pq;
        unordered_map<int,int>mp;
        string ans = "";

        for(auto i : s){
            mp[i-'a']++;
        }

        for(auto i : mp){
            pq.push({i.first + 'a',i.second});
        }
        
        while(!pq.empty()){
            char first = pq.top().first;
            int freq1 = pq.top().second;
            pq.pop();

            if(ans=="" || ans.back()!=first){
                string add1(min(freq1, repeatLimit),first);
                freq1 -= min(freq1, repeatLimit);
                ans += add1;
            }
            
            if(pq.size()==0)    
                break;

            char second = pq.top().first;
            int freq2 = pq.top().second;
            pq.pop();

            if(freq1 == 0){
                string add2(min(freq2, repeatLimit),second);
                freq2 -= min(freq2, repeatLimit);
                ans += add2;
            }
            else{
                ans += second;
                freq2--;
            }
            
            if(freq1)
                pq.push({first,freq1});
            if(freq2)
                pq.push({second,freq2});

        }
        return ans;
    }
};