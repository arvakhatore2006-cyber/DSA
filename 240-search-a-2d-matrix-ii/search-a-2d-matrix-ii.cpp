class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rows = 0;
        int col = m-1;
        while(rows<n&&col>=0){
            if(matrix[rows][col]== target) return true;
            else if(matrix[rows][col]<target) rows++;
            else col--;

        }
          return false;
    }
 
};