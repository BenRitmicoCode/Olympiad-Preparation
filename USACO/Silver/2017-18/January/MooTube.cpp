#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int,int>> arr[100100];
bool visited[100100];
queue<int> q1;
int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
	int n,q;
	fin>>n>>q;
	for(int i=0;i<n-1;i++){
	    int p,q,r;
	    fin>>p>>q>>r;
	    arr[p].push_back(make_pair(q,r));
	    arr[q].push_back(make_pair(p,r));
	}
	while(q--){
	    int k,v;
	    fin>>k>>v;
	    q1.push(v);
	    while(!q1.empty()){
	       int hold = q1.front();
	       q1.pop();
	       for(auto x:arr[hold]){
	           if(visited[x.first]||x.first == v){
	               continue;
	           }
	           if(x.second<k){
	               continue;
	           }
	           visited[x.first] = true;
	           q1.push(x.first);
	       }
	    }
	    int ans = 0;
	    for(int i=0;i<=n;i++){
	        if(visited[i]){
	            ans++;
	        }
	        visited[i] = false;
	    }
	    fout<<ans<<endl;
	}
	
}
