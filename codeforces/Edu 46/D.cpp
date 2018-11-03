#include <iostream>
using namespace std;
const long long N = 10e3+5;
long long a[N];
long long dp[N];
long long c[N][N];
long long mod = 998244353;
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	for(long long i=0;i<N;i++){
	    c[i][0] = (long long)1;
	     c[i][i] = c[i][0];
	    for(long long j=1;j<i;j++){
	        c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
	    }
	}
	dp[n] = 1;
	for(long long i=n-1;i>=0;i--){
	    if(a[i]<=0){
	        continue;
	    }
	    
	    for(long long j=i+a[i]+1;j<=n;j++){
	        dp[i]= (dp[i] + (dp[j] * c[j-i-1][a[i]])%mod)%mod;
	    }
	}
	for(long long i=1;i<n;i++){
	    dp[i] = (dp[i-1] + dp[i])%mod;
	}
	std::cout<<dp[n-1]<<endl;
}
