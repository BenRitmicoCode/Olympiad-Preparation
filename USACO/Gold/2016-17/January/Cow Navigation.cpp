#include <iostream>
#include <queue>
#include <tuple>
#include <fstream>
#include <vector>
using namespace std;
	int n;
int dp[25][25][25][25][25];
int grid[25][25];
int dy[5] = {1,0,-1,0};
int dx[5] = {0,1,0,-1};
bool check(int x,int y){
    if(grid[x][y] == 0){
        return false;
    }
    if(x<1||x>n||y<1||y>n){
        return false;
    }
    return true;
}
pair<int,int> nextpos(int x, int y, int dir){
    if(x==n && y==n){
        return make_pair(x,y);
    }
    int x1 = x+dx[dir];
    int y1 = y+dy[dir];
    if(check(x1,y1)){
        return make_pair(x1,y1);
    }else{
        return make_pair(x,y);
    }
}
int main() {
    ifstream fin("cownav.in");
    ofstream fout("cownav.out");
	fin>>n;

	for(int i=n;i>0;i--){
	    for(int j=1;j<=n;j++){
	        char x;
	        fin>>x;
	        if(x=='E'){
	            grid[j][i] = 1;
	        }else{
	            grid[j][i] = 0;
	        }
	    }
	}
	queue<tuple<int,int,int,int,int,int>> q1;
    
    q1.push(make_tuple(0,1,1,1,1,0));
    dp[1][1][1][1][0] = 1;
	while(!q1.empty()){
	    auto hold = q1.front();
	    q1.pop();
	    int moves= get<0>(hold);
	    int x1 = get<1>(hold);
	    int y1 = get<2>(hold);
	    int x2 = get<3>(hold);
	    int y2 = get<4>(hold);
	    int dir = get<5>(hold);
	    //fout<<moves<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<dir<<endl;
	    if(x1==n && y1==n && x2 == n && y2 == n){
	        fout<<moves;
	        return 0;
	    }
	    int l =(dir+3)%4;
	    int r =( dir+1)%4;
	    
	    if(!dp[x1][y1][x2][y2][r]){
	        q1.push(make_tuple(moves+1,x1,y1,x2,y2,r));
	        dp[x1][y1][x2][y2][r] = 1;
	    }
	    if(!dp[x1][y1][x2][y2][l]){
	        q1.push(make_tuple(moves+1,x1,y1,x2,y2,l));
	        dp[x1][y1][x2][y2][l] = 1;
	    }
	    auto nextpos1 = nextpos(x1,y1,dir);
	    auto nextpos2 = nextpos(x2,y2,(dir+1)%4);
	    if(!dp[nextpos1.first][nextpos1.second][nextpos2.first][nextpos2.second][dir]){
	        q1.push(make_tuple(moves+1,nextpos1.first,nextpos1.second,nextpos2.first,nextpos2.second,dir));
	        dp[nextpos1.first][nextpos1.second][nextpos2.first][nextpos2.second][dir] = 1;
	    }
	}
}
