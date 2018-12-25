#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
const int MAXN = 50000;
vector<int> arr[MAXN];
int dist[MAXN];
int dist2[MAXN];
int dist3[MAXN];
int b,e,p,n,m;
void bfs1(){
    queue<int> q1;
    q1.push(1);
    dist[1] = 0;
    while(!q1.empty()){
        int curr = q1.front();
        q1.pop();
        for(auto x:arr[curr]){
            if(dist[x] == 0 && x!=1){
                dist[x] = dist[curr]+1;
                q1.push(x);
            }
        }
    }
}

void bfs2(){
    queue<int> q1;
    q1.push(2);
    dist2[2] = 0;
    while(!q1.empty()){
        int curr = q1.front();
        q1.pop();
        for(auto x:arr[curr]){
            if(dist2[x] == 0 && x!=2){
                dist2[x] = dist2[curr]+1;
                q1.push(x);
            }
        }
    }
}

void bfs3(){
    queue<int> q1;
    q1.push(n);
    dist3[n] = 0;
    while(!q1.empty()){
        int curr = q1.front();
        q1.pop();
        for(auto x:arr[curr]){
            if(dist3[x] == 0 && x!=n){
                dist3[x] = dist3[curr]+1;
                q1.push(x);
            }
        }
    }
}
int main() {
	ifstream fin("piggyback.in");
	ofstream fout("piggyback.out");
	fin>>b>>e>>p>>n>>m;
	for(int i=0;i<m;i++){
	    int x,y;
	    fin>>x>>y;
	    arr[x].push_back(y);
	    arr[y].push_back(x);
	}
	int ans = 1000000000;
	bfs1();
	bfs2();
	bfs3();
	for(int i=1;i<=n;i++){
	    ans = min(ans,(b*dist[i])+(e*dist2[i])+(p*dist3[i]));
	    
	}
	fout<<ans<<endl;
}
