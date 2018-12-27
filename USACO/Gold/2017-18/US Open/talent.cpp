#include <iostream>
#include <fstream>
using namespace std;
const long long MAXN = 1010;
long long weights[MAXN];
long long talent[MAXN];
long long dp[MAXN];
long long n,w;
bool check(long long x){
    for(long long i=0;i<=w;i++){
        dp[i] = -1000000000;
    }
    dp[0] =0;
    for(long long i=0;i<n;i++){
        long long temp = 1000*talent[i] -(x*weights[i]);
        long long toinc = weights[i];
        for(long long j=w;j>=0;j--){
            long long k = min(w,j+toinc);
            if(dp[j]!=-1000000000){
                if(dp[k]<dp[j]+temp){
                   // fout<<talent[i]<<" "<<weights[i]<<" "<<x<<" "<<(x*weights[i])<<endl;
                    dp[k] = dp[j]+temp;
                }
            }
        }
    }
    if(dp[w]>=0){
       // fout<<x<<" "<<dp[w]<<endl;
        return true;
    }
    return false;
}

int main() {
    ifstream fin("talent.in");
    ofstream fout("talent.out");
	fin>>n>>w;
	for(long long i=0;i<n;i++){
	    fin>>weights[i]>>talent[i];
	}
	long long l = 0;
	long long r = 1000*250*1000;
	long long ans = 0;
	while(l<=r){
	    long long mid = (l+r)/2;
	    if(check(mid)){
	        ans = mid;
	        l = mid+1;
	    }else{
	        r =mid-1;
	    }
	}
    fout<<ans<<endl;
    
}
