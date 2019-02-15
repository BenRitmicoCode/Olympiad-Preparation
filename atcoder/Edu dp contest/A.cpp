#include <iostream>
using namespace std;
const int MAXN = 100100;
int arr[MAXN];
int dp[MAXN];
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	dp[0] = 0;
	dp[1] = abs(arr[1]-arr[0]);
	for(int i=2;i<n;i++){
	    dp[i] = min(dp[i-1]+abs(arr[i-1]-arr[i]),dp[i-2]+abs(arr[i-2]-arr[i]));
	}
	cout<<dp[n-1];
}
