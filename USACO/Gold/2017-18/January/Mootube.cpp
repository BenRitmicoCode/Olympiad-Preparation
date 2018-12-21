#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int,int>> arr[100100];
bool visited[100100];
queue<int> q1;
vector<pair<pair<int,int>,int>> queries;
vector<pair<int,pair<int,int>>> edges;
int fathers[100100];
int size[100100];

int anc(int x,int depth){
    if(fathers[x]==x){
        if(size[x] == 0){   
            size[x] = depth;
        }
       return x;
       
    }
    fathers[x] = anc(fathers[x],depth+1);
    size[x] = size[fathers[x]];
    return fathers[x];
}
int unite(int a, int b){
    int x = anc(a,1);
    int y = anc(b,1);
    fathers[x] = y;
    size[x] = size[y]+size[x];
    size[y] = size[x];
    
}
int ans[100100];
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
	    edges.push_back(make_pair(r,make_pair(p,q)));
	}
	for(int i=0;i<=100000;i++){
	    fathers[i] = i;
	}
	sort(edges.begin(),edges.end());
    for(int i=0;i<q;i++){
	    int k,v;
	    fin>>k>>v;
	    queries.push_back(make_pair(make_pair(k,v),i));
	}
	sort(queries.begin(),queries.end());

	int last = edges.size()-1;
	for(int i=q-1;i>=0;i--){
	    int threshold = queries[i].first.first;
	    int node = queries[i].first.second;
	    int trye = queries[i].second;
	   // fout<<threshold<<endl;
	    while(edges[last].first>=threshold){
	        int from = edges[last].second.first;
	        int to = edges[last].second.second;
	        unite(to,from);
	        last--;
	    }
	    ans[trye] = size[anc(node,1)]-1;
	   //fout<<threshold<<" "<<node<<" "<<trye<<" "<<ans[trye]<<endl;
	}
	for(int i=0;i<q;i++){
	    fout<<ans[i]<<endl;
	}
}
