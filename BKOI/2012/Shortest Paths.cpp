#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int MAXN = 2010;
int temp3[MAXN];
int val[MAXN];
vector<int> tree[MAXN];
int visited[MAXN];
int dist[MAXN];
int par[MAXN];
int visited2[MAXN];
int dist2[MAXN];
vector<int> toadd[MAXN];
vector<int> todel[MAXN];
multiset<int> s1;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
vector<pair<int,int>> v1[MAXN];


void dfs(int node,int level){
    //dfs through the dijkstra's tree
    
    int curr = max(level,val[node]);
    
    temp3[node] = curr;
   // cout<<node<<" "<<temp3[node]<<" "<<par[node]<<endl;
    for(auto x:tree[node]){
        dfs(x,curr);
    }
}
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        v1[x].push_back(make_pair(w,y));
        v1[y].push_back(make_pair(w,x));
        
    }
    for(int i=0;i<=n;i++){
        dist[i] = 1e9;
        val[i] = -1;
        dist2[i] = 1e9;
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        val[x] = i;
    }
    //shortest path from node a
    q1.push(make_pair(0,a));
    dist[a] = 0;
    while(!q1.empty()){
        
        auto hold = q1.top();
        q1.pop();
        if(visited[hold.second]){
            continue;
        }
        visited[hold.second] = true;
        if(hold.second!=a){
            //build the shortest path tree
           
            tree[par[hold.second]].push_back(hold.second);
        }
        for(auto x:v1[hold.second]){
            if(val[x.second] == val[hold.second]+1||dist[x.second]>x.first+hold.first){
                dist[x.second] = x.first+hold.first;
                par[x.second] = hold.second;
               // cout<<x.second<<" "<<par[x.second]<<endl;
                q1.push(make_pair(x.first+hold.first,x.second));
            }
        }
    }
    q1.push(make_pair(0,b));
    dist2[b] = 0;
    //reverse shortest path
    while(!q1.empty()){
        auto hold = q1.top();
        q1.pop();
        if(visited2[hold.second]){
            continue;
        }
        visited2[hold.second] = true;
        dist2[hold.second] = hold.first;
        for(auto x:v1[hold.second]){
            q1.push(make_pair(x.first+hold.first,x.second));
        }
    }
    
    //find the closest node on the shortest path from each node
    dfs(a,1);
    
    for(int i=1;i<=n;i++){
        for(auto x:v1[i]){
            //check each edge
            
            //if on the shortest path continue
            if(max(val[i],val[x.second])-min(val[i],val[x.second]) == 1){
                continue;
            }
            //only if the closest node to u is smaller than the closest node to v, we process the edge(if not, we return to it later)
            //if it's closest to the same node(was in the subtree of the same node in the dijkstra's tree, we can't consider that path)
            if(temp3[i]>=temp3[x.second]){
                continue;
            }
            
            //path length
            int twice = x.first + dist[i]+dist2[x.second];
           
            //this is where the new path can be added
            toadd[temp3[i]].push_back(twice);
            //the new path can no longer be used from this position
            todel[temp3[x.second]].push_back(twice);
        }
    }
    for(int i=1;i<k;i++){
        
        
         for(int j=0;j<todel[i].size();j++){
            s1.erase(s1.find(todel[i][j]));
            
        }
        for(int j=0;j<toadd[i].size();j++){
            
            s1.insert(toadd[i][j]);
        }
       
        
        //if no possible paths to traverse output -1
        if(s1.empty()){
            cout<<-1<<endl;
        }else{
            //output the shortest path
            cout<<*s1.begin()<<endl;
        }
    }
    
}
