class Solution {
public:
    int sumbyD(vector<int>& arr, int divisior) {
        int sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            sum += ceil((double)arr[i] / (double)divisior);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& arr, int limit) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());

        while (low <= high) {
            int mid = (low + high) / 2;

            if (sumbyD(arr, mid) <= limit) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};