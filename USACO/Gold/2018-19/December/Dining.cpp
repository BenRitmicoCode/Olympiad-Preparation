#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 60000;
vector<int> v1[MAXN];
map<pair<int,int>,int> edges;
int haybales[MAXN];
int haybaleval[MAXN];
map<int,int> dist;
void dijkstras(int n){
    set<pair<int,int>> visited;
    visited.insert(make_pair(0,n));
    while(!visited.empty()){
        int curr = visited.begin()->second;
        visited.erase(visited.begin());
      //  fout<<n<<" "<<dist[curr]<<endl;
        for(auto x:v1[curr]){
            if(dist.count(x) == 0||dist[x]>dist[curr]+edges[make_pair(x,curr)]){
                dist[x] = dist[curr]+edges[make_pair(x,curr)];
                visited.insert(make_pair(dist[x],x));
            }
        }
    }
}
int main() {
    ifstream fin("dining.in");
    ofstream fout("dining.out");
	int n,m,k;
	fin>>n>>m>>k;
	for(int i=0;i<m;i++){
	    int x,y,w;
	    fin>>x>>y>>w;
	    v1[x].push_back(y);
	    v1[y].push_back(x);
	    edges[make_pair(x,y)] = w;
	    edges[make_pair(y,x)] = w;
	}
	for(int i=0;i<k;i++){
	    fin>>haybales[i]>>haybaleval[i];
	}
	dijkstras(n);
	map<int,int> tempdist = dist;
	for(int i=0;i<k;i++){
	    v1[n+1].push_back(haybales[i]);
	   
        edges[make_pair(haybales[i],n+1)] = dist[haybales[i]]-haybaleval[i];
	    edges[make_pair(n+1,haybales[i])] = dist[haybales[i]]-haybaleval[i];
	}
	dist.clear();
	dijkstras(n+1);
	for(int i=1;i<n;i++){
	    if(dist[i]<=tempdist[i]){
	        fout<<1<<endl;
	    }else{
	        fout<<0<<endl;
	    }
	}
}
