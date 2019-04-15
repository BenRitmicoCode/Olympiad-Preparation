#include <iostream>

using namespace std;
const int MAXN = 500010;
int ans1,ans2;
int val[MAXN];
int exists[MAXN];
int dp[MAXN][3];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>val[i]>>exists[i];
        if(exists[i]){
            exists[i] = 0;
        }else{
            exists[i] = 1;
        }
    }
    val[n+1] = k;
    for(int i=1;i<=n;i++){
        dp[i][0] = exists[i];
        dp[i][1] = val[i];
        int diff  = val[i+1]-val[i];
        for(int j=1;j<i;j++){
            if(dp[j][1]>=diff||val[j]>=diff){
                break;
            }
            if(dp[j][0]+exists[i]>dp[i][0]){
                dp[i][0] = dp[j][0]+exists[i];
                dp[i][1] = dp[j][1]+val[i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i][0]>ans1){
            ans1 = dp[i][0];
            ans2 = dp[i][1];
        }
    }
    if(ans2 == 0){
        ans2++;
    }
    
    cout<<ans1<<endl;
    cout<<k-ans2<<endl;
}
