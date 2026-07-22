class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int maxOnes = -1;
        int rowIndex = 0;

        for (int i = 0; i < n; i++) {

            int cnt = 0;

            // Count 1s in current row
            for (int j = 0; j < m; j++) {
                cnt += mat[i][j];
            }

            // Update only if strictly greater
            if (cnt > maxOnes) {
                maxOnes = cnt;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};