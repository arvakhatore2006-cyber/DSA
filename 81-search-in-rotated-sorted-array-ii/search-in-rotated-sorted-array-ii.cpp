class Solution {
public:
    bool search(vector<int>& arr, int target) {
      int n = arr.size(); // size of the array
        for (int i = 0; i < n; i++) {
            if (arr[i] == target) return true; // if found, return true
        }
        return false; // not found  
    }
};