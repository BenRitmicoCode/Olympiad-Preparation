#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
using namespace std;
const long long MAXN = 260;
vector<pair<int,pair<int,int>>> edges;
vector<pair<int,int>> v1[MAXN];
int n,m;
int dp[MAXN];
int dp2[MAXN];
int dp3[MAXN];
void dijkstras1(){
    priority_queue<pair<int,int>> q1;
    q1.push(make_pair(0,1));
    for(int i=0;i<=n;i++){
        dp[i] = 1e9;
    }
    dp[1] = 0;
    while(!q1.empty()){
        auto hold = q1.top();
        int dist = -1*hold.first;
        int from = hold.second;
        q1.pop();
        for(auto x:v1[from]){
            if(dp[x.first]>dist + x.second){
                dp[x.first] = x.second+dist;
                q1.push(make_pair(-1*dp[x.first],x.first));
            }
        }
    }
}
void dijkstras2(){
    priority_queue<pair<int,int>> q1;
    q1.push(make_pair(0,n));
    for(int i=0;i<=n;i++){
        dp2[i] = 1e9;
    }
    dp2[n] = 0;
    while(!q1.empty()){
        auto hold = q1.top();
        int dist = -1*hold.first;
        int from = hold.second;
        q1.pop();
        for(auto x:v1[from]){
            if(dp2[x.first]>dist + x.second){
                dp2[x.first] = x.second+dist;
                q1.push(make_pair(-1*dp2[x.first],x.first));
            }
        }
    }
}
int main() {
    ifstream fin("rblock.in");
    ofstream fout("rblock.out");
   fin>>n>>m;
   for(int i=0;i<m;i++){
       int x,y,w;
       fin>>x>>y>>w;
       v1[x].push_back(make_pair(y,w));
       v1[y].push_back(make_pair(x,w));
       edges.push_back(make_pair(w,make_pair(x,y)));
   }
   dijkstras1();
   dijkstras2();
   sort(edges.begin(),edges.end());
   reverse(edges.begin(),edges.end());
   int ans = 0;
   int path = dp[n];
   for(int i=0;i<=n;i++){
       dp3[i] = dp[i];
   }
   for(auto x:edges){
       int w = x.first;
       int from = x.second.first;
       int to = x.second.second;
       if(dp3[from]+dp2[to]+w == dp3[n]||dp3[to]+dp2[from]+w == dp3[n]){
           for(int i=0;i<v1[from].size();i++){
               if(v1[from][i].first == to){
                   v1[from][i].second = 2*w;
               }
           }
           for(int i=0;i<v1[to].size();i++){
               if(v1[to][i].first == from){
                   v1[to][i].second = 2*w;
               }
           }
           dijkstras1();
           ans = max(ans,dp[n]-path);
           for(int i=0;i<v1[from].size();i++){
               if(v1[from][i].first == to){
                   v1[from][i].second = w;
               }
           }
           for(int i=0;i<v1[to].size();i++){
               if(v1[to][i].first == from){
                   v1[to][i].second = w;
               }
           }
           
       }
     
   }
   fout<<ans<<endl;

}
