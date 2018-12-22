#include <iostream>
#include <fstream>
#include <vector> 
using namespace std;
int f[300];
int n,b;
int ans = 99999999;
bool visited[300][300];
vector<pair<int,int>> v1;
void re(int pos,int bootind){
    if(pos == n-1){
        ans = min(ans,bootind);
        return;
    }
    
    if(visited[pos][bootind]){
        return;
    }
    visited[pos][bootind] = true;
    //cout<<pos<<" "<<bootind<<endl;
 
    for(int i=pos+1;i<=min(n-1,pos+v1[bootind].second);i++){
        if(f[i]<=v1[bootind].first){
            re(i,bootind);
        }
    }
    for(int i=bootind+1;i<b;i++){
        if(f[pos]<=v1[i].first){
            re(pos,i);
        }
    }
}

int main() {
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
	fin>>n>>b;
	for(int i=0;i<n;i++){
	    fin>>f[i];
	}
	for(int i=0;i<b;i++){
	    int x,y;
	    fin>>x>>y;
	    v1.push_back(make_pair(x,y));
	}
	
	re(0,0);
	fout<<ans<<endl;
	
}
