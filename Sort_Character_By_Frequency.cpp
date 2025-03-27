#include<bits/stdc++.h>

using namespace std;

string frequencySort(string s) {
    unordered_map<char,int> freqMap;

    for(int i = 0; i<s.length(); i++){
        freqMap[s[i]]++;
    }

     priority_queue<pair<int, char>> maxHeap;
    for (auto it : freqMap) {
        maxHeap.push({it.second, it.first}); 
    }

    string result;
    while (!maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();

        
        result.append(top.first, top.second);
    }

    return result;
}

int main() {

    string s;

    
    cout << "Enter a string: ";
    cin >> s;

    
    cout << "Sorted by frequency: " << frequencySort(s) << endl;

    return 0;
}

/*
    Example Test Cases:

    Input 1:
    s = "tree"
    Output: "eert" or "eetr"

    Input 2:
    s = "cccaaa"
    Output: "cccaaa" or "aaaccc"

    Input 3:
    s = "Aabb"
    Output: "bbAa" or "bbaA"
*/