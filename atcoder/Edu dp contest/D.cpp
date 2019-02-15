#include <iostream>
using namespace std;
 
const long long MAXN = 100100;
long long w[MAXN];
long long c[MAXN];
long long dp[110][100100];
 
int main() {
	long long n,x;
	cin>>n>>x;
    for(long long i=0;i<n;i++){
        cin>>w[i]>>c[i];
    }
    for(long long i=0;i<=n;i++){
        for(long long j=0;j<=x;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            }
            else if(w[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],c[i-1]+dp[i-1][j-w[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
           // cout<<i<<" "<<j<<" "<<w[i-1]<<" "<<c[i-1]<<endl;
        }
    }
    cout<<dp[n][x];
	
}
