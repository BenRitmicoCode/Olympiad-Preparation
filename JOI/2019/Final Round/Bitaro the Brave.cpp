#include <iostream>
 
using namespace std;
const long long MAXN = 3010;
char arr[MAXN][MAXN];
long long dp[MAXN][MAXN];
long long dp2[MAXN][MAXN];
int main(){
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=m;j>=1;j--){
            dp[i][j] = dp[i][j+1]+(arr[i][j] == 'O');
            
        }
    }
    for(long long j=1;j<=m;j++){
        for(long long i=n;i>=1;i--){
            dp2[i][j] = dp2[i+1][j] + (arr[i][j] == 'I');
        }
    }
    long long ans =0;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            if(arr[i][j] == 'J'){
                ans+= ((long long)1*(dp2[i][j]*dp[i][j]));
            }
        }
    }
    cout<<ans<<endl;
}
