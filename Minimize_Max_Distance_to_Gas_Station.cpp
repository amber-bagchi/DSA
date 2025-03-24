#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int>& arr, int k, int n, double mid) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        int diff = arr[i] - arr[i - 1];
        if (mid > 0) count += ceil((double)diff / mid) - 1;
    }
    return count <= k; 
}

double findSmallestMaxDist(vector<int>& stations, int k) {
    sort(stations.begin(), stations.end());

    int n = stations.size();
    double s = 0;
    double e = stations[n - 1] - stations[0];
    double ans = e;

    while ((e - s) > 1e-6) { 
        double mid = s + (e - s) / 2.0;
        if (isPossible(stations, k, n, mid)) {
            ans = mid;
            e = mid;  
        } else {
            s = mid;  
        }
    }

    return ans; 
}




int main() {
    int n, k;
    cout << "Enter number of stations: ";
    cin >> n;

    vector<int> stations(n);
    cout << "Enter station positions: ";
    for (int i = 0; i < n; i++) {
        cin >> stations[i];
    }

    cout << "Enter number of extra stations (k): ";
    cin >> k;


    double result = findSmallestMaxDist(stations, k);
    cout << "Smallest maximum distance after adding extra stations: " << result << endl;

    return 0;
}

/*

Input:

Enter number of stations: 10
Enter station positions: 1 2 3 4 5 6 7 8 9 10
Enter number of extra stations (k): 9

Output:

Smallest maximum distance after adding extra stations: 1.000000


*/