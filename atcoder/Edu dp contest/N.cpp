#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
long long arr[450];
long long dp[450][450];
long long pref[450];
long long dprec(long long l,long long r){
    
    if(dp[l][r]){
        return dp[l][r];
    }
    if(l == r){
        
        return dp[l][r] = 0;
    }
    long long holdmin = dprec(l+1,r);
    for(int i=l+1;i<r;i++){
        holdmin = min(holdmin,dprec(l,i)+dprec(i+1,r));
    }
    return dp[l][r] = holdmin + pref[r]-pref[l-1];
}
int main() {
    long long n;
    cin>>n;
    vector<long long> v1;
    pref[0] = 0;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        v1.push_back(arr[i]);
        pref[i+1] = arr[i]+pref[i];
    }
    cout<<dprec(1,n);
    
}
