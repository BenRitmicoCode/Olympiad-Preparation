#include <iostream>
#include <fstream>
using namespace std;
int arr[150];
int dp[150][150][150]; //ith day, last breakout on day j, k breakouts in total
int main() {
    ifstream fin("taming.in");
    ofstream fout("taming.out");
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
	    fin>>arr[i];
	}
	for(int i=0;i<=n;i++){
	    for(int j=0;j<=n;j++){
	        for(int k=0;k<=n;k++){
	            dp[i][j][k] = 10000;
	        }
	    }
	}
	if(arr[0] == 0){
	    dp[0][0][1] = 0;
	}else{
	    dp[0][0][1] = 1;
	}
	for(int i=1;i<n;i++){
	    for(int j=0;j<=i;j++){
	        for(int k=1;k<=i+1;k++){
	            if(j<i){
	                dp[i][j][k] = dp[i-1][j][k];
	            }else{
	                for(int x=0;x<i;x++){
	                    dp[i][j][k] = min(dp[i][j][k],dp[i-1][x][k-1]);
	                }
	            }
	            if(arr[i]!=abs(i-j)){
	                dp[i][j][k]++;
	            }
	           // cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
	        }
	    }
	}
	for(int k=1;k<=n;k++){
	    int ans = 10000;
	    for(int i=0;i<n;i++){
	        ans = min(ans,dp[n-1][i][k]);
	    }
	    fout<<ans<<endl;
	}
	
}
