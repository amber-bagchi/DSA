#include<bits/stdc++.h>

using namespace std;

bool isIsomorphic(string s, string t) {

    unordered_map<char, int> charIndexS;
      unordered_map<char, int> charIndexT;

      for (int i = 0; i < s.length(); i++) {
          if (charIndexS.find(s[i]) == charIndexS.end()) {
              charIndexS[s[i]] = i;
          }

          if (charIndexT.find(t[i]) == charIndexT.end()) {
              charIndexT[t[i]] = i;
          }

          if (charIndexS[s[i]] != charIndexT[t[i]]) {
              return false;
          }
      }

      return true; 


  }



int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (isIsomorphic(s, t)) {
        cout << "Output: true" << endl;
    } else {
        cout << "Output: false" << endl;
    }

    return 0;
}