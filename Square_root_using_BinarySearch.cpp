#include <bits/stdc++.h>

using namespace std;

long long int sqrtbinarysearch(int x){
    int s = 0;
    int e = x;
    long long int mid = s + (e-s)/2;
    long long int ans = -1;
    while(s<=e){
        long long int square = mid * mid;
        if(square==x){
            ans = mid;
            return ans;
        }
        if(square<x){
            ans = mid;
            s = mid +1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

double sqrtdecimal(int x, int precision, int answer){

    double factor = 1;
    double ans = answer;

    for(int i=0; i<precision; i++){
        factor = factor/10;

        for(double j=ans; j*j<x; j=j+factor){
            ans = j;

        }
    }

    return ans;

}

int main() {

    int x;
    cout<<"Enter the Number to find its square root: "<<endl;
    cin>>x;

    int ans = sqrtbinarysearch(x);
    double to_decimal = sqrtdecimal(x, 3, ans);

    cout<<"The square root of "<<x<<" is: "<<ans<<endl;
    cout<<"The square root of "<<x<<" to decimal is: "<<to_decimal<<endl; 



    
return 0;
}