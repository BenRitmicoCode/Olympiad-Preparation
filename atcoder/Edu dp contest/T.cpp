#include <iostream>
 
using namespace std;
const long long MAXN = 3010;
const long long MOD = 1e9+7;
long long dp[MAXN][MAXN];
long long dp2[MAXN];
int main(){
    long long n;
    cin>>n;
    string s;
    cin>>s;
    for(long long i=1;i<=n;i++){
       
        dp2[i] = 1;
    }
    for(long long i=1;i<n;i++){
        if(s[i-1] == '<'){
            for(long long j=1;j<=i+1;j++){
                
                dp[i][j] = dp2[j-1];
               // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
            
        }else{
            for(long long j=1;j<=i+1;j++){
                
                dp[i][j] = ((dp2[n]-dp2[j-1]) + MOD)%MOD;
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
            
        }
        dp2[0] = dp[i][0];
        for(long long j=1;j<=n;j++){
            dp2[j] = dp2[j-1] + dp[i][j];
            dp2[j]%=MOD;
        }
        
    }
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        ans+=dp[n-1][i];
        ans%=MOD;
    }
    cout<<ans<<endl;
}
