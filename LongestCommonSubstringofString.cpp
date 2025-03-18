#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &arr) {
    if(arr.empty()) return "";

    string ans = "";
    for(int i = 0; i < arr[0].length(); i++) {
        char current = arr[0][i]; 
        for(int j = 1; j < arr.size(); j++) {
            if(i >= arr[j].length() || arr[j][i] != current) {
                return ans; 
            }
        }
        ans += current; 
    }
    return ans; 
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> s(n);
    cin.ignore(); 

    cout << "Enter the strings:" << endl;
    for(int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }

    string result = longestCommonPrefix(s);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
