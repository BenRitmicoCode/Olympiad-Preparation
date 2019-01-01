#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
long long grid[110][110];
long long dp[110][110];
	long long n,t;
long long dx[20] = {3,-3,0,0,1,1,-1,-1,2,2,-2,-2,1,-1,0,0};
long long dy[20] = {0,0,3,-3,2,-2,2,-2,1,-1,1,-1,0,0,-1,1};
long long d2x[8] = {-2,0,-1,-1,0};
long long d2y[8] = {0,2,1,0,1};
priority_queue<pair<long long,pair<long long,long long>>> q1;
bool check(long long x,long long y){
    if(x>n||y>n||x<1||y<1){
        return false;
    }
    return true;
}
int main() {
    ifstream fin("visitfj.in");
    ofstream fout("visitfj.out");
	fin>>n>>t;
	for(long long i=n;i>=1;i--){
	    for(long long j=1;j<=n;j++){
	        fin>>grid[j][i];
	        dp[i][j] = -1;
	    }
	}
	dp[1][n] = 0;
	q1.push(make_pair(0,make_pair(1,n)));
	long long ans = 1000000000;
	while(!q1.empty()){
	    auto hold = q1.top();
	    q1.pop();
	    long long dist = -1*hold.first;
	    long long x1 = hold.second.first;
	    long long y1 = hold.second.second;
	    long long sum = x1+y1;
	    for(long long i=0;i<5;i++){
	        long long currx = n+d2x[i];
	        long long curry = 1+d2y[i];
	        if(x1 == currx && y1 == curry){
	            
	            ans =  min(ans,dist+(t*(abs(d2x[i])+abs(d2y[i]))));
	          //  fout<<x1<<" "<<y1<<" "<<ans<<" "<<1234<<endl;
	        }
	    }
	    for(long long i=0;i<16;i++){
	        long long currx = x1+dx[i];
	        long long curry = y1+dy[i];
	       
	        if(!check(currx,curry)){
	            continue;
	        }
	        if(dp[currx][curry]==-1||dp[currx][curry]>dist+(3*t)+grid[currx][curry]){
	            dp[currx][curry] = dist+(3*t)+grid[currx][curry];
	           // fout<<currx<<" "<<curry<<" "<<dp[currx][curry]<<endl;
	            q1.push(make_pair(-1*dp[currx][curry],make_pair(currx,curry)));
	        }
	    }
	}
	fout<<min(ans,dp[n][1])<<endl;
	
}
