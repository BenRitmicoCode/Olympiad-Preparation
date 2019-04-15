#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long MAXN = 3e5+5;
long long col[MAXN];
vector<long long> v1[MAXN];
long long dp[MAXN][70];
int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    for(long long i=1;i<=n;i++){
        cin>>col[i];
    }
    for(long long i=1;i<=m;i++){
        long long x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
        
    }
    for(long long i=1;i<=n;i++){
        dp[i][(1<<col[i])] = 1;
    }
    for(long long i=1;i<=(1<<(k+1));i++){
        for(long long j=1;j<=n;j++){
            if((1<<col[j])&i){
                
                for(long long x:v1[j]){
                    if((1<<col[x])&i){
                     //   cout<<j<<" "<<x<<" "<<i-(1<<col[j])<<" "<<dp[k][i-(1<<col[j])]<<endl;
                        dp[j][i] += dp[x][i-(1<<col[j])];
                    }
                }
            }
        }
    }
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=(1<<(k+1));j++){
           // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            ans+=dp[i][j];
        }
    }
    cout<<ans-n<<endl;
}
