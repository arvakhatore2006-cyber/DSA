class Solution {
public:

    int helper(const string &s, int i, long long num, int sign) {

        // Stop if end of string or non-digit
        if (i >= s.size() || !isdigit(s[i])) {
            return (int)(sign * num);
        }

        // Add current digit
        num = num * 10 + (s[i] - '0');

        // Check overflow
        if (sign * num <= INT_MIN) {
            return INT_MIN;
        }

        if (sign * num >= INT_MAX) {
            return INT_MAX;
        }

        // Recursive call
        return helper(s, i + 1, num, sign);
    }

    int myAtoi(string s) {

        int i = 0;

        // Skip spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Handle sign
        int sign = 1;

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Convert string to integer
        return helper(s, i, 0, sign);
    }
};