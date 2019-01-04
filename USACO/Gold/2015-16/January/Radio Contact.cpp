#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
vector<pair<int,int>> v1;

vector<pair<int,int>> v2;
map<char,pair<int,int>> m1;
const int MAXN = 1010;
int dist(int x1,int y1,int x2,int y2){
    return ((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1));
}
int dp[MAXN][MAXN];
int main() {
    ifstream fin("radio.in");
    ofstream fout("radio.out");
	int n,m;
	fin>>n>>m;
	int fx,fy;
	fin>>fx>>fy;
	int bx,by;
	fin>>bx>>by;
	string s1;
	fin>>s1;
	string s2;
	fin>>s2;
	m1['N'] = make_pair(0,1);
	m1['S'] = make_pair(0,-1);
	m1['E'] = make_pair(1,0);
	m1['W'] = make_pair(-1,0);
	v1.push_back(make_pair(fx,fy));
	for(int i=1;i<=n;i++){
	    auto hold = m1[s1[i-1]];
	    int nextx = v1[i-1].first+hold.first;
	    int nexty = v1[i-1].second+ hold.second;
	    v1.push_back(make_pair(nextx,nexty));
	    //fout<<nextx<<" "<<nexty<<endl;
	}
	v2.push_back(make_pair(bx,by));
	for(int i=1;i<=m;i++){
	    auto hold = m1[s2[i-1]];
	    int nextx = v2[i-1].first + hold.first;
	    int nexty = v2[i-1].second + hold.second;
	    v2.push_back(make_pair(nextx,nexty));
	    //fout<<nextx<<" "<<nexty<<endl;

	}
	dp[0][0] = dist(v1[0].first,v1[0].second,v2[0].first,v2[0].second);
	for(int i=0;i<=n;i++){
	    for(int j=0;j<=m;j++){
	        if(i ==0 && j==0){
	            dp[0][0] = dist(v1[0].first,v1[0].second,v2[0].first,v2[0].second);
	            continue;
	        }
	        else if(i== 0){
	            dp[i][j] = dist(v1[i].first,v1[i].second,v2[j].first,v2[j].second) + dp[i][j-1];
	            continue;
	        }else if(j == 0){
	            dp[i][j] = dist(v1[i].first,v1[i].second,v2[j].first,v2[j].second) + dp[i-1][j];
	            continue;
	        }
	        dp[i][j] = dist(v1[i].first,v1[i].second,v2[j].first,v2[j].second) + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
	    }
	}
	fout<<dp[n][m]-dp[0][0]<<endl;
}
