#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
const long long MAXN = 200100;
const long long MOD = 1e9 + 7;
vector<long long> v1[MAXN];

int query[MAXN];
vector<int> ord;
long long n,m,q;
vector<int> g2[MAXN];
bool ok[MAXN];
int actual[MAXN];
bool notok[MAXN];
long long ans;
vector<pair<int,int>> edges;
int dis[MAXN];
void bfs1(int s){
    for(int i=1;i<=n;i++){
        dis[i] = -1;
    }
    dis[s] = 0;
    queue<int> q1;
    q1.push(s);
    while(!q1.empty()){
        int curr = q1.front();
        q1.pop();
        for(auto x:v1[curr]){
            if(dis[x] == -1){
                dis[x] = 1+dis[curr];
                q1.push(x);
            }
        }
    }
}
int bfs2(int a,int b){
    if(dis[a] == dis[b]){
        return 0;
    }
    if(dis[a]>dis[b]){
        swap(a,b);
    }
    g2[a].push_back(b);
    int res= 0;
    if(ok[a]){
        queue<int> q1;
        q1.push(b);
        while(!q1.empty()){
            int v = q1.front();
            q1.pop();
            if(ok[v]){
                continue;
            }
            ok[v] = true;
            res++;
            for(auto x:g2[v]){
                q1.push(x);
            }
        }
    }
    return res;
}
int main() {
  
   cin>>n>>m>>q;
   //edges.push_back(make_pair(0,0));
   for(int i=0;i<m;i++){
       int x,y;
       cin>>x>>y;
       x--;
       y--;
       v1[x].push_back(y);
       v1[y].push_back(x);
       edges.push_back(make_pair(x,y));
   }
   bfs1(0);
  
   for(int i=0;i<q;i++){
       cin>>query[i];
       query[i]--;
   }
   for(int i=0;i<=q;i++){
       notok[i] = false;
       
   }
    for(int i=0;i<q;i++){
       ord.push_back(query[i]);
       notok[query[i]] = true;
      
   }
   for(int i=0;i<m;i++){
       if(!notok[i]){
           ord.push_back(i);
          
       }
     
   }
   int last = 0;
   ok[0] = true;
   actual[m] = 0;
   for(int i=m-1;i>=0;i--){
       int a = edges[ord[i]].first;
       int b = edges[ord[i]].second;
     //  cout<<a<<" "<<b<<endl;
       int tempans = bfs2(a,b);
      
       actual[i] = tempans+ last;
       last = actual[i];
   }
   for(int i=0;i<q;i++){
       cout<<n-1-actual[i+1]<<endl;
   }
   
   
}
