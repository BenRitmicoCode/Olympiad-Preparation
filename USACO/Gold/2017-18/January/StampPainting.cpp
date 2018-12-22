#include <iostream>
#include <fstream>
using namespace std;
long long dp[1000100];
const long long mod = 1e9+7;
long long powe(long long x,long long y){
    long long res = 1;
    x%=mod;
    while(y>0){
        if(y%2 == 1){
            res*=x;
            res%=mod;
        }
        x=x*x;
        x%=mod;
        y/=2;
    }
    return res;
}
int main() {
    ifstream fin("spainting.in");
    ofstream fout("spainting.out");
	long long n,m,k;
	fin>>n>>m>>k;
	dp[0] = 1;
	long long tempsum = 1;
	for(long long i=1;i<=n;i++){
	    if(i<k){
	        dp[i] = (dp[i-1]*m)%mod;
	        tempsum+=dp[i];
	       
	        tempsum%=mod;
	        continue;
	    }
	    
	    tempsum+=mod;
	    tempsum-=dp[i-k];
	    tempsum%=mod;
	    dp[i] = tempsum*(m-1);
	    dp[i]%=mod;
	    tempsum+=dp[i];
	    tempsum%=mod;
	    //cout<<dp[i]<<" "<<tempsum<<endl;
	}
	fout<<(powe(m,n)+mod-dp[n])%mod<<endl;
}
