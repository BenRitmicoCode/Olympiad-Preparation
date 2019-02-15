#include <iostream>
using namespace std;
 
const long long MAXN = 100100;
 
long long dp[MAXN];
 
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=100000;i++){
        dp[i] = 1000000001;
    }
    dp[0] = 0;
    for(int i=0;i<n;i++){
        int w,v;
        cin>>w>>v;
        for(int j=100000;j>=0;j--){
            if(j-v<0){
              //  cout<<dp[j]<<" "<<dp[j-v+1]+w<<endl;
                break;
            }
 
            if(dp[j]>dp[j-v]+w && dp[j-v]+w<=k){
                dp[j] = dp[j-v]+w;
            }
        }
    }
    for(int i=100000;i>=0;i--){
        if(dp[i]!=1000000001 && dp[i]<=k){
            cout<<i;
            return 0;
        }
    }
}
