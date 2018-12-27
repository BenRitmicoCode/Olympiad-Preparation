#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 10010;
const int MAXK = 1010;
int arr[MAXN];
int dp[MAXN]; // dp[i][k] = upto the ith cow, k cows in the last group,
int main() {
    ifstream fin("teamwork.in");
    ofstream fout("teamwork.out");
	int n,k;
	fin>>n>>k;
	for(int i=0;i<n;i++){
	    fin>>arr[i];
	}
	dp[0] = arr[0];
	for(int i=1;i<n;i++){
	    int holdmax = arr[i];
	    for(int j=i;j>=0;j--){
	        if(i-j+1>k){
	            break;
	        }
	        holdmax = max(holdmax,arr[j]);
	        if(j==0){
	            dp[i] = max(dp[i],(holdmax*(i-j+1)));
	            continue;
	        }
	        dp[i] = max(dp[i],dp[j-1]+(holdmax*(i-j+1)));
	        //fout<<i<<" "<<dp[i]<<endl;
	    }
	    
	}
	fout<<dp[n-1]<<endl;
}
