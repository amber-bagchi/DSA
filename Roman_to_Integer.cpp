#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int num = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        
        if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
            num -= romanMap[s[i]];
        } else {
            num += romanMap[s[i]];
        }
    }

    return num;
}

int main() {
    
    string s;
    cout << "Enter a Roman numeral: ";
    cin >> s;

    
    cout << "Integer value: " << romanToInt(s) << endl;

    return 0;
}
