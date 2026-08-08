class Solution {
public:
    string frequencySort(string& s) {

        unordered_map<char, int> freq;

        // Count characters
        for (char ch : s) {
            freq[ch]++;
        }

        // Convert to vector
        vector<pair<char, int>> arr;

        for (auto x : freq) {
            arr.push_back({x.first, x.second});
        }

        // Sort by frequency
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Build answer
        string ans = "";

        for (auto x : arr) {
            ans += string(x.second, x.first);
        }

        return ans;
    }
};