class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;

        auto isValid = [&](int len, char ch) {
            int count = 0;
            int matches = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == ch) matches++;
                else matches = 0;

                if (matches >= len) count++;
                if (count == 3) return true;
            }
            return false;
        };

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int low = 1, high = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (isValid(mid, ch)) {
                    ans = max(ans, mid); 
                    low = mid + 1;     
                } else {
                    high = mid - 1;     
                }
            }
        }

        return ans;
    }
};
D