class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int ind = 0;
        int count = 1;
        bool possible = true;
        for(int i = 0;i<n;i++){
            if(sentence[i]==' '){
                count++;
                possible = true;
                ind = 0;
                continue;
            }
            else if(possible){
                if(sentence[i]!=searchWord[ind]){
                    possible = false;
                    continue;
                }
                ind++;
                if(ind == searchWord.size())return count;
            }
        }
        return -1;
    }
};