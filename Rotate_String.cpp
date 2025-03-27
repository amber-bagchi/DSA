#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if (s.size() != goal.size()) return false;

        queue<char> q1, q2;

        
        for (char ch : s) {
            q1.push(ch);
        }

        
        for (char ch : goal) {
            q2.push(ch);
        }

       
        if (q1 == q2) {
            return true;
        }

        int k = goal.size();  

        
        while (k--) {
            char ch = q2.front();
            q2.pop();
            q2.push(ch);

            if (q1 == q2) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    string s, goal;

    
    cout << "Enter original string (s): ";
    cin >> s;
    cout << "Enter goal string (goal): ";
    cin >> goal;

    
    bool result = sol.rotateString(s, goal);
    cout << (result ? "true" : "false") << endl;

    return 0;
}

/*
    Example Test Cases:

    Input 1:
    s = "abcde"
    goal = "cdeab"
    Output: true

    Explanation: "abcde" rotated gives "bcdea", then "cdeab", which matches "goal".

    Input 2:
    s = "abcde"
    goal = "abced"
    Output: false

    Explanation: No rotation of "abcde" matches "goal".
*/
