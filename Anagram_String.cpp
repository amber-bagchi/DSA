#include <iostream>
using namespace std;


    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false; 

        int count[26] = {0}; 

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; 
            count[t[i] - 'a']--; 
        }

        
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }


int main() {

    string s, t;


    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    cout << (isAnagram(s, t) ? "true" : "false") << endl;

    return 0;
}

/*
    Example Test Cases:

    Input 1:
    s = "anagram"
    t = "nagaram"
    Output: true

    Input 2:
    s = "rat"
    t = "car"
    Output: false

    Input 3:
    s = "listen"
    t = "silent"
    Output: true
*/
