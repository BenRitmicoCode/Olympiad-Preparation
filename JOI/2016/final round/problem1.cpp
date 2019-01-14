#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long MAXN = 100010;
long long arr[MAXN];
long long dp[MAXN];
long long n,m,k;
long long rec(long long x,long long y,long long z){
    if(x>=n){
        return 0;
    }
    if(dp[x]){
        return dp[x];
    }
    long long maxo = arr[x];
    long long mino = arr[x];
    long long ans = 1e18;
    for(long long i=x;i<min(n,x+y);i++){
        //long long incto = i+x;
        maxo = max(maxo,arr[i]);
        mino = min(mino,arr[i]);
        long long diff = maxo-mino;
        long long cost = z+(i-x+1)*diff;
        long long final = cost + rec(i+1,y,z);
        ans = min(final,ans);
    }
    return dp[x] = ans;
    
}
int main() {
    cin>>n>>m>>k;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        
    }
    cout<<rec(0,m,k)<<endl;
}
