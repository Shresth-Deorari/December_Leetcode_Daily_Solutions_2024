class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int zero = 0;
        unordered_set<int>st;
        for(auto i : arr){
            zero += i==0;
            st.insert(i);
        }
        if(zero>1)return true;
        for(auto i : arr){
            if(!(i&1) && i!=0)
            if(st.find(i/2)!=st.end()){
                cout<<i<<endl;
                return true;
            }
        }
        return false;
    }
};