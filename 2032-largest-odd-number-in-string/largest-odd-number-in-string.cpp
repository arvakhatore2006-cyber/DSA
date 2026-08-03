class Solution {
public:
    string largestOddNumber(string s) {
        int ind = -1;

        // Find the last odd digit
        for (int i = s.length() - 1; i >= 0; i--) {
            if ((s[i] - '0') % 2 == 1) {
                ind = i;
                break;
            }
        }

        // If no odd digit exists
        if (ind == -1)
            return "";

        // Return substring from beginning to last odd digit
        return s.substr(0, ind + 1);
    }
};