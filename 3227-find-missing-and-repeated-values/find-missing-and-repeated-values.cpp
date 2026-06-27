class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        int N = n * n;

        int xr = 0;

        // XOR all elements of matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                xr ^= grid[i][j];
            }
        }

        // XOR numbers from 1 to n*n
        for (int i = 1; i <= N; i++) {
            xr ^= i;
        }

        // Rightmost set bit
        int bit = xr & (-xr);

        int zero = 0, one = 0;

        // Divide matrix elements into two groups
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] & bit)
                    one ^= grid[i][j];
                else
                    zero ^= grid[i][j];
            }
        }

        // Divide numbers 1...N into two groups
        for (int i = 1; i <= N; i++) {
            if (i & bit)
                one ^= i;
            else
                zero ^= i;
        }

        // Check which one is repeated
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == zero)
                    cnt++;
            }
        }

        if (cnt == 2)
            return {zero, one};

        return {one, zero};
    }
};