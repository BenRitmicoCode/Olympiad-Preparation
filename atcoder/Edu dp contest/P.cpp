#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
const long long MAXN = 100100;
const long long MOD = 1e9 + 7;
vector<long long> v1[MAXN];
long long dp[MAXN][5];
void dfs(long long curr,long long par){
    dp[curr][0] = dp[curr][1] = 1;
    for(auto x:v1[curr]){
        if(x == par){
            continue;
        }
        dfs(x,curr);
        dp[curr][0]*=dp[x][1];
        dp[curr][0]%=MOD;
        dp[curr][1]*=(dp[x][1]+dp[x][0]);
        dp[curr][1]%=MOD;
    }
}
int main() {
   long long n;
   cin>>n;
   for(long long i=0;i<n-1;i++){
       long long x,y;
       cin>>x>>y;
       v1[x].push_back(y);
       v1[y].push_back(x);
       
   }
   dfs(1,1);
   cout<<(dp[1][0]+dp[1][1])%MOD<<endl;
}
