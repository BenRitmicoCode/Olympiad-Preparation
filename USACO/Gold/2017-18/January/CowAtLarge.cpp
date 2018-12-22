#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<int> arr[101000];
int distroot[101000];
int ans = 0;
int distleaf[101000];
void dfs(int curr,int par){
    
    if(curr!=par){
        distroot[curr] = min(distroot[curr],distroot[par]+1);
    }else{
        distroot[curr] = 0;
    }
    for(auto x:arr[curr]){
        if(x == par){
            continue;
        }
        dfs(x,curr);
        distleaf[curr] = min(distleaf[curr],distleaf[x]+1);
    }
    if(distleaf[curr] == 1000000000){
        distleaf[curr] = 0;
    }
  //  fout<<curr<<" "<<distleaf[curr]<<" "<<distroot[curr]<<endl;
}
void dfs2(int curr,int par){
    if(curr!=par){
        distleaf[curr] = min(distleaf[curr],distleaf[par]+1);
    }
    for(auto x:arr[curr]){
        if(x==par){
            continue;
        }
        dfs2(x,curr);
    }
   
}
void dfs3(int curr,int par){
    if(curr!=par && distleaf[curr] <= distroot[curr] && distroot[par]<distleaf[par]){
        ans++;
    }
    for(auto x:arr[curr]){
        if(x==par){
            continue;
        }
        dfs3(x,curr);
    }
}

int main() {
    ifstream fin("atlarge.in");
    ofstream fout("atlarge.out");
	int n,m;
	fin>>n>>m;
	for(int i=1;i<n;i++){
	    int x,y;
	    fin>>x>>y;
	    arr[x].push_back(y);
	    arr[y].push_back(x);
	    
	}
	for(int i=1;i<=n;i++){
	    distleaf[i] = 1000000000;
	    distroot[i] = 1000000000;
	}
	dfs(m,m);
	dfs2(m,m);
	dfs3(m,m);
	fout<<ans<<endl;
}
