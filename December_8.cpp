class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by their end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> maxEndingHere(n, 0);

        // Fill maxEndingHere: max value of an event ending before or at i
        maxEndingHere[0] = events[0][2];
        for (int i = 1; i < n; ++i) {
            maxEndingHere[i] = max(maxEndingHere[i - 1], events[i][2]);
        }

        int result = 0;

        // Iterate through events and find the maximum sum of two non-overlapping events
        for (int i = 0; i < n; ++i) {
            // First event is events[i]
            int currentValue = events[i][2];

            // Binary search to find the last event that ends before the current event starts
            int lo = 0, hi = i - 1, lastNonOverlapping = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][1] < events[i][0]) {
                    lastNonOverlapping = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            // If there's a non-overlapping event, add its value
            if (lastNonOverlapping != -1) {
                currentValue += maxEndingHere[lastNonOverlapping];
            }

            // Update the result
            result = max(result, currentValue);
        }

        return result;
    }
};
