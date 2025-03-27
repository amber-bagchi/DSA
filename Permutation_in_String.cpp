#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkEqual(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false; 

        int count1[26] = {0}, count2[26] = {0};
        int n = s1.size(), m = s2.size();

        
        for (int i = 0; i < n; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        
        if (checkEqual(count1, count2)) return true;

        
        for (int i = n; i < m; i++) {
            
            count2[s2[i] - 'a']++;

           
            count2[s2[i - n] - 'a']--;

           
            if (checkEqual(count1, count2)) return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    string s1, s2;

    
    cout << "Enter first string (s1): ";
    cin >> s1;
    cout << "Enter second string (s2): ";
    cin >> s2;

    
    bool result = sol.checkInclusion(s1, s2);
    cout << (result ? "true" : "false") << endl;

    return 0;
}

/*
    Example Test Cases:
    
    Input 1:
    s1 = "ab"
    s2 = "eidbaooo"
    Output: true

    Explanation: "ba" (permutation of "ab") is in "eidbaooo".

    Input 2:
    s1 = "ab"
    s2 = "eidboaoo"
    Output: false

    Explanation: No permutation of "ab" exists in "eidboaoo".
*/
