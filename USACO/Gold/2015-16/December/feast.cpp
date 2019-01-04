#include <iostream>
#include <fstream>
using namespace std;
int t,a,b;
int dp[5000001];
void check(int i, int water){
    if(i>t){
        return;
    }
    if(dp[i]){
        return;
    }
   // fout<<i<<endl;
    dp[i] = 1;
    check(i+a,water);
    check(i+b,water);
    if(!water){
        check(i/2,1);
    }
    
}
int main() {
    ifstream fin("feast.in");
    ofstream fout("feast.out");
	fin>>t>>a>>b;
	int ans = 0;
	check(0,0);
	for(int i=0;i<=t;i++){
	    if(dp[i]){
	        ans = max(ans,i);
	    }
	}
	fout<<ans<<endl;
}
