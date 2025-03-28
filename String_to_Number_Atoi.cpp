#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string s) {
    int result = 0;
    int sign = 1;
    int i = 0;
    int n = s.length();


    while (i < n && s[i] == ' ') {
        i++;
    }


    if (i < n && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';

        
        if (result > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}


int main() {
    cout << myAtoi("42") << endl;          // Output: 42
    cout << myAtoi("   -42") << endl;      // Output: -42
    cout << myAtoi("1337c0d3") << endl;    // Output: 1337
    cout << myAtoi("0-1") << endl;         // Output: 0


    return 0;
}
