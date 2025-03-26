#include <iostream>
using namespace std;


    string largestOddNumber(string num) {
        int e = num.length() - 1;

        
        while (e >= 0) {
            if ((num[e] - '0') % 2 != 0) {
                return num.substr(0, e + 1); 
            }
            e--;
        }

        return ""; 
    }


int main() {

    string num;

   
    cout << "Enter a number string: ";
    cin >> num;

    
    string result = largestOddNumber(num);
    cout << "Largest Odd Number Substring: " << result << endl;

    return 0;
}

/*
Example Test Cases:

Input 1:
Enter a number string: 4206
Output:
Largest Odd Number Substring: ""

Input 2:
Enter a number string: 52
Output:
Largest Odd Number Substring: "5"

Input 3:
Enter a number string: 35427
Output:
Largest Odd Number Substring: "35427"
*/