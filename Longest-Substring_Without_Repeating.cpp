#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringBrueteForce(string s) {
    int max_len = 0;

    for(int i = 0; i<s.length(); i++){
        unordered_map<char, int> m;
        int len = 0;
        for(int j = i; j<s.length(); j++){
            if(m[s[j]] == 1){
               break;
            }
            len = j - i + 1;
            m[s[j]] = 1;
            max_len = max(len,max_len);
        }
    }

    return max_len;
    
}

int lengthOfLongestSubstring(string s) {
        
    unordered_map<char,int> m;
    int l = 0, r = 0;
    int max_len = 0;

    while(r<s.length()){

        if(m.find(s[r]) != m.end() && m[s[r]]>=l){
            l = m[s[r]] + 1;
        }
        max_len = max(max_len, r - l + 1);
        m[s[r]] = r;
        r++;

    }
    return max_len;
    
}




int main() {
    
    cout << lengthOfLongestSubstringBrueteForce("abcabcbb") << endl;  // Output: 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;     // Output: 1
    cout << lengthOfLongestSubstring("pwwkew") << endl;    // Output: 3
    return 0;
}