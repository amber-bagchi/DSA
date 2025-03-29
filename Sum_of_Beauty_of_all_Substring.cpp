#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int beauty(int count[]) {
    int maxi = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < 26; i++) {
        maxi = max(count[i], maxi);
        if (count[i] >= 1) {
            mini = min(count[i], mini);
        }
    }
    return maxi - mini;
}

int beautySum(string s) {
    int res = 0;

    for (int i = 0; i < s.length(); i++) {
        int count[26] = {0};
        for (int j = i; j < s.length(); j++) {
            count[s[j] - 'a']++;
            res = res + beauty(count);
        }
    }
    return res;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = beautySum(s);
    cout << "The beauty sum of the string is: " << result << endl;

    return 0;
}

/*
Test Cases:

1. Input: "aabcb"
   Output: 5
   Explanation: 
   - Possible substrings and their beauty differences:
     ["a", "aa", "aab", "aabc", "aabcb", "a", "ab", "abc", "abcb", "b", "bc", "bcb", "c", "cb", "b"]
   - The sum of all beauty differences is 5.

2. Input: "zzz"
   Output: 0
   Explanation:
   - All substrings have only 'z', so beauty difference is 0.
*/
