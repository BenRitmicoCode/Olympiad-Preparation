#include <iostream>
#include <iomanip>
using namespace std;
 
const long long MAXN = 3010;
 
long long dp[MAXN][MAXN][2];
long long arr[MAXN];
long long f(long long x,long long y,long long turn){
    if(dp[x][y][turn]){
        return dp[x][y][turn];
    }
    if(x>y){
        return 0;
    }
   // cout<<x<<" "<<y<<" "<<turn<<endl;
    if(turn%2 == 1){
        return dp[x][y][turn] = max(arr[x]+f(x+1,y,1-turn),arr[y]+f(x,y-1,1-turn));
    }else{
        return dp[x][y][turn] = min(f(x+1,y,1-turn)-arr[x],f(x,y-1,1-turn)-arr[y]);
    }
}
int main() {
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<f(1,n,1)<<endl;
}
