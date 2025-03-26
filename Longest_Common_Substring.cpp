#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";  

    sort(strs.begin(), strs.end()); 

    int e = strs.size() - 1;
    string ans = "";

    for (int i = 0; i < strs[0].length(); i++) {
        if (strs[0][i] == strs[e][i]) {
            ans += strs[0][i]; 
        } else {
            break; 
        }
    }

    return ans;
}

int main() {
    vector<string> strs;
    
   
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    
    cout << "Enter " << n << " strings:\n";
    strs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: \"" << result << "\"\n";

    return 0;
}

/*
Example Test Cases:

Test Case 1:
Input:
3
flower flow flight
Output:
Longest Common Prefix: "fl"

Test Case 2:
Input:
3
dog racecar car
Output:
Longest Common Prefix: ""

Test Case 3:
Input:
2
apple applepie
Output:
Longest Common Prefix: "apple"
*/
