#include <iostream>
using namespace std;
 
const int MAXN = 100100;
int arr[MAXN];
int dp[MAXN];
int main() {
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	dp[0] = 0;
 
	for(int i=1;i<n;i++){
	    dp[i] = 1000000000;
	    for(int j=i-1;j>=max(i-k,0);j--){
	        dp[i] = min(dp[j]+abs(arr[j]-arr[i]),dp[i]);
	        
	    }
	}
	cout<<dp[n-1];
}
