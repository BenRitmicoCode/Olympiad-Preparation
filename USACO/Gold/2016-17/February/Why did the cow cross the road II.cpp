#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 1010;
int down[MAXN];
int up[MAXN];
int dp[MAXN][MAXN];
int main() {
    ifstream fin("nocross.in");
    ofstream fout("nocross.out");
    int n;
    fin>>n;
	for(int i=0;i<n;i++){
	    fin>>down[i];
	    
	}
	for(int i=0;i<n;i++){
	    fin>>up[i];
	}
	dp[0][0] = (int)abs(up[0]-down[0])<=4;
	for(int i=1;i<n;i++){
	    dp[i][0] = max(dp[i-1][0],(int)(abs(up[0]-down[i])<=4));
	}
	for(int i=1;i<n;i++){
	    dp[0][i] = max(dp[i-1][0],(int)(abs(up[i]-down[0])<=4));
	}
	for(int i=1;i<n;i++){
	    for(int j=1;j<n;j++){
	        dp[i][j] = max(dp[i-1][j-1]+(int)(abs(abs(up[j]-down[i])<=4)),max(dp[i-1][j],dp[i][j-1]));
	    }
	}
	fout<<dp[n-1][n-1]<<endl;
}
