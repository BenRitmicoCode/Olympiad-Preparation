#include <iostream>
using namespace std;

const int MAXN = 100100;
int arr[MAXN][3];
int dp[MAXN][3];
pair<int,int> nums(int x){
    if(x ==1 ){
        return make_pair(0,2);
    }
    if(x == 2){
        return make_pair(0,1);
    }
    if(x == 0){
        return make_pair(1,2);
    }
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    for(int j=0;j<3;j++){
	        cin>>arr[i][j];
	    }
	}
    dp[0][1] = arr[0][1];
    dp[0][0] = arr[0][0];
    dp[0][2] = arr[0][2];

	for(int i=1;i<n;i++){
	   for(int j=0;j<3;j++){
	       auto hold = nums(j);
	       dp[i][j] = max(dp[i-1][hold.first]+arr[i][j],dp[i-1][hold.second]+arr[i][j]);
	      // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	   }
	    
	}
	std::cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}
