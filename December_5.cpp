class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n || j < n) {
            // Skip underscores in start
            while (i < n && start[i] == '_') i++;
            // Skip underscores in target
            while (j < n && target[j] == '_') j++;

            // If one pointer is out of bounds and the other is not, it's invalid
            if (i < n && j < n) {
                // If the characters don't match
                if (start[i] != target[j]) return false;

                // Check constraints for 'L' and 'R'
                if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {
                    return false;
                }

                // Move both pointers forward
                i++;
                j++;
            } else if (i < n || j < n) {
                // If one string has unmatched characters
                return false;
            }
        }

        return true;
    }
};
