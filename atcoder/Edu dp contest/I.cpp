#include <iostream>
#include <iomanip>
using namespace std;
 
const long long MAXN = 3001;
 
double dp[MAXN][MAXN];
double p[MAXN];
 
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i+1][j+1] += dp[i][j]*p[i];
            dp[i+1][j] += dp[i][j]*(1-p[i]);
            
        }
    }
    double ans = 0;
    for(int i=(n+1)/2;i<=n;i++){
        ans+=dp[n][i];
    }
    cout<<setprecision(10)<<ans<<endl;
}
