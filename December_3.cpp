class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0,ind = 0;
        int n = s.size();
        string ans;
        while(i<n){
            if(ind<spaces.size() && i == spaces[ind]){
                ans += ' ';
                ind++;
            }
            else{
                ans += s[i++];
            }
        }
        return ans;
    }
};