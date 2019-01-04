#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
int n,m;
int dp[1010][1010][2];
int grid[1010][1010];
priority_queue<pair<pair<int,int>,pair<int,int>>> q1;
void add(int x,int y, int d,bool s){
    if(dp[x][y][s]>d||dp[x][y][s] == -1){
        q1.push(make_pair(make_pair(-1*d,x),make_pair(y,s)));
        dp[x][y][s] = d;
    }
}
void trymoving(int x,int y,int dist,bool colour,int dx,int dy){
    if(x<0||y<0||x>=n||y>=m||grid[x][y] == 0){
        return;
    }
    if(grid[x][y] == 1){
        add(x,y,dist,colour);
    }
    if(grid[x][y] == 2){
        add(x,y,dist,true);
    }
    if(grid[x][y] == 3 && colour){
        add(x,y,dist,colour);
    }
    if(grid[x][y] == 4){
        while(grid[x][y] == 4){
            int nx = x+dx;
            int ny = y+dy;
            if(nx<0||ny<0||nx>=n||ny>=m||grid[nx][ny] == 0||(grid[nx][ny] == 3 && !colour)){
                break;
            }
            x=nx;
            y=ny;
            dist++;
        }
        add(x,y,dist,false);
    }
}
int main() {
    ifstream fin("dream.in");
    ofstream fout("dream.out");
	fin>>n>>m;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        fin>>grid[i][j];
	        dp[i][j][0] = -1;
	        dp[i][j][1] = -1;
	    }
	}
	
	add(0,0,0,false);
	while(!q1.empty()){
	    auto hold = q1.top();
	    q1.pop();
	    int d = -1*hold.first.first;
	    int x = hold.first.second;
	    int y = hold.second.first;
	    int o = hold.second.second;
	    if(x == n-1 && y == m-1){
	        fout<<d<<endl;
	        return 0;
	    }
	    trymoving(x-1,y,d+1,o,-1,0);
	    trymoving(x,y-1,d+1,o,0,-1);
	    trymoving(x+1,y,d+1,o,1,0);
	    trymoving(x,y+1,d+1,o,0,1);
	}
	fout<<-1<<endl;
}
