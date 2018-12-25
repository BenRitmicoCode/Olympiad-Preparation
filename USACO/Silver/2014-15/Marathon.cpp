#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<pair<int,int>> v1;
int dp[510][510];
int main() {
    ifstream fin("marathon.in");
    ofstream fout("marathon.out");
	int n,k;
	fin>>n>>k;
	v1.push_back(make_pair(0,0));
	for(int i=0;i<n;i++){
	    int x,y;
	    fin>>x>>y;
	    v1.push_back(make_pair(x,y));
	}
	for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = 1000000000;
        }
	}
	dp[1][0] = 0;
	for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            for(int l=i+1;l<=n && j+l-i-1<=k;l++){
                int shifti = l;
                int shiftj = j+l-i-1;
                dp[shifti][shiftj] = min(dp[shifti][shiftj],dp[i][j]+abs(v1[i].first-v1[l].first)+abs(v1[i].second-v1[l].second));
                //fout<<shifti<<" "<<shiftj<<" "<<dp[shifti][shiftj]<<endl;
                
            }
        }
	}
	fout<<dp[n][k]<<endl;
}
