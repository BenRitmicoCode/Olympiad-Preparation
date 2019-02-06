#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const long long MOD = 1e9 + 9;
const long long MAXN = 1010;
const long long MAXM = 1010;
const long long MAXK = 12;
long long dp[MAXN][MAXM][MAXK];
long long a[MAXN];
long long N,M,K;
long long b[MAXM];
long long rec(long long i,long long j,long long k){
    if(k>K){
        return 0;
    }
    if(k == K){
        return 1;
    }
    if(i==N||j==M){
        return 0;
    }

    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    dp[i][j][k] = 0;
    dp[i][j][k] += rec(i+1,j,k);
    
    dp[i][j][k]%=MOD;
    dp[i][j][k] += rec(i,j+1,k);
    
    dp[i][j][k]%=MOD;
    dp[i][j][k] -= rec(i+1,j+1,k);

    dp[i][j][k]+=MOD;
    dp[i][j][k]%=MOD;
    if(a[i]>b[j]){
        dp[i][j][k] += rec(i+1,j+1,k+1);
        
        dp[i][j][k]%=MOD;
    }
    dp[i][j][k] += MOD;
    dp[i][j][k]%=MOD;
   // cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
    return dp[i][j][k];
    
}
int main(){
  
    cin>>N>>M>>K;
    for(long long i=0;i<N;i++){
        cin>>a[i];
    }
    for(long long i=0;i<M;i++){
        cin>>b[i];
    }
    sort(a,a+N);
    sort(b,b+M);
    for(long long i=0;i<MAXN;i++){
        for(long long j=0;j<MAXM;j++){
            for(long long k=0;k<MAXK;k++){
                dp[i][j][k] = -1;
            }
        }
    }
    cout<<rec(0,0,0)<<endl;
}
