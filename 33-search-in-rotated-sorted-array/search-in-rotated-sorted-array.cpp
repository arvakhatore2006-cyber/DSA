class Solution {
public:
   
      int search(vector<int>& nums, int target) {

        // Loop through each element in the array
        for (int i = 0; i < nums.size(); i++) {

            // If current element matches target, return index
            if (nums[i] == target) {
                return i;
            }
        }

        // If not found, return -1
        return -1;
    }
};  
    
