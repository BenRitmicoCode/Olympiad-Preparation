#include <iostream>
 
using namespace std;
const long long MAXN = (long long)1e5+5;
long long arr[MAXN];
long long n,l,r;
bool check2(long long val){
    bool dp[n+(long long)1][n+(long long)1];
    for(long long i=0;i<=n;i++){
        for(long long j=0;j<=n;j++){
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    for(long long i=(long long)1;i<=n;i++){
        for(long long j=1;j<=i;j++){
            for(long long k = 0;k<i;k++){
                if(dp[k][j-1] && ((arr[i]-arr[k])|val) == val){
                    dp[i][j] = true;
                    break;
                }
            }
            
        }
        
    }
    for(long long i=l;i<=r;i++){
        if(dp[n][i]){
            return true;
        }
    }
    return false;
}
bool check(long long val){
    long long dp[n+(long long)1];
    for(long long i=0;i<=n;i++){
        dp[i] = (long long)1e9;
    }
    dp[0] = 0;
    for(long long i=(long long)1;i<=n;i++){
        for(long long j=0;j<i;j++){
            if(((arr[i]-arr[j])|val) == val){
                dp[i] = min(dp[i],dp[j]+(long long)1);
            }
        }
        
    }
    
    return dp[n]>=l && dp[n]<=r;
}
int main(){
    
    cin>>n>>l>>r;
    for(long long i=(long long)1;i<=n;i++){
        cin>>arr[i];
        arr[i]+=arr[i-(long long)1];
    }
    long long val = ((long long)1<<50)-(long long)1;
    
    for(long long i=49;i>=0;i--){
        if(l == 1){
            if(check(val^((long long)1<<i))){
                
                val^=((long long)1<<i);
               // cout<<val<<endl;
            }
        }else{
            if(check2(val^((long long)1<<i))){
                
                val^=((long long)1<<i);
               // cout<<val<<endl;
            }
        }
    }
    cout<<val<<endl;
}
