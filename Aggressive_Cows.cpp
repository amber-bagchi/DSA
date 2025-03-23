#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid){

    int n = stalls.size();
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i = 0; i<n; i++){
        if(stalls[i] - lastPos >= mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            lastPos = stalls[i];
        }
    }

    return false;

}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.

    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int s = 1;
    int e = stalls[n-1] - stalls[0];
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){

        if(isPossible(stalls,k, mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        mid = s + (e-s)/2;
        
        
    }
    return ans;

}

int main() {
    int n, k;
    cout << "Enter number of stalls: ";
    cin >> n;
    
    vector<int> stalls(n);
    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    
    cout << "Enter number of cows: ";
    cin >> k;

    int result = aggressiveCows(stalls, k);
    cout << "Largest minimum distance: " << result << endl;

    return 0;
}


/*
Input:

Enter number of stalls: 5
Enter stall positions: 1 2 8 4 9
Enter number of cows: 3


Output:
Largest minimum distance: 3
*/