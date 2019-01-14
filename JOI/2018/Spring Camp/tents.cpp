#include <iostream>

using namespace std;
long long dp[3010][3010];
const long long mod = 1e9+7;
int main() {
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<3010;i++){
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            
                dp[i][j] = dp[i-1][j];

            dp[i][j] += (4*j*dp[i-1][j-1]);
            dp[i][j]+=mod;
            dp[i][j]%=mod;
            dp[i][j] += ((j*(j-1))/2)*dp[i-1][j-2];
            dp[i][j]+=mod;
            dp[i][j]%=mod;
            dp[i][j] += (j*(i-1))*dp[i-2][j-1];
            dp[i][j]+=mod;
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][m]-1<<endl;
}
