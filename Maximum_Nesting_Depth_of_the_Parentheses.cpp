#include <iostream>
#include <string>
#include <algorithm>  

using namespace std;

int maxDepth(string s) {
    int count = 0;      
    int maxcount = 0;   

    for (char ch : s) {
        if (ch == '(') {
            count++;
            maxcount = max(maxcount, count); 
        } 
        else if (ch == ')') {
            count--;
        }
    }

    return maxcount;
}

int main() {
    
    string s;
    cout << "Enter a valid parentheses string: ";
    cin >> s;

    
    int result = maxDepth(s);

   
    cout << "Maximum depth of nested parentheses: " << result << endl;

    return 0;
}

/*
🔹 **Example Test Cases:**
-------------------------
Input:  "(((1)+(2)))"
Output: 3

Input:  "(1+(2*3)+((8)/4))+1"
Output: 3

Input:  "(1)"
Output: 1

Input:  "((()))"
Output: 3

Input:  "abc(def(ghi))jkl"
Output: 2

*/
