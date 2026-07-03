class Solution {
public:
    // Find the maximum pile
    int findMax(vector<int>& piles) {
        int maxi = piles[0];
        for (int i = 1; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    // Calculate total hours needed at a given eating speed
    long long calculateTotalHours(vector<int>& piles, int hourly) {
        long long totalH = 0;

        for (int i = 0; i < piles.size(); i++) {
            // Integer ceiling division
            totalH += (1LL * piles[i] + hourly - 1) / hourly;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};