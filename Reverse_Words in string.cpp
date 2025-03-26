#include <iostream>
#include <string>
#include <algorithm>  

using namespace std;


string reverseWords(string s) {
    int n = s.length();
    reverse(s.begin(), s.end());
    string ans = "";

    for (int i = 0; i < n; i++) {
        string word = "";
        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0) {
            ans += " " + word;
        }
    }

    return ans.substr(1); 
}

int main() {
    
    cout << "Enter a string: ";
    string s;
    getline(cin, s);  

    
    string result = reverseWords(s);

   
    cout << "Reversed words: " << result << endl;

    return 0;
}