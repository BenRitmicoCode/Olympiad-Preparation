//will probably TLE

#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 7010;
set<pair<int,int>> s1[MAXN];
set<pair<int,int>> s2[MAXN];
int dp[MAXN];
vector<pair<int,pair<int,int>>> edges;
int dp2[MAXN];
    int n,m,q;
void dijkstras(){
    priority_queue<pair<int,int>> q1;
    q1.push(make_pair(0,0));
    dp[0] = 0;
 
    while(!q1.empty()){
        auto hold = q1.top();
        int dist = -1*hold.first;
        int from = hold.second;
           q1.pop();
        for(auto x:s1[from]){
            int to = x.first;
            int w = x.second;
            if(dp[to]>dp[from]+w){
                dp[to] = dp[from]+w;
                q1.push(make_pair(-1*dp[to],to));
            }
        }
    }
}
void dijkstras2(){
    priority_queue<pair<int,int>> q1;
    q1.push(make_pair(0,n-1));
    dp2[n-1] = 0;
    while(!q1.empty()){
        auto hold = q1.top();
        int dist = -1*hold.first;
        int from = hold.second;
           q1.pop();
        for(auto x:s1[from]){
            int to = x.first;
            int w = x.second;
            if(dp2[to]>dp2[from]+w){
                dp2[to] = dp2[from]+w;
                q1.push(make_pair(-1*dp2[to],to));
            }
        }
    }
}
int dijkstras3(int u,int v){
    priority_queue<pair<int,int>> q1;
    q1.push(make_pair(0,u));
    int dp3[7010];
    for(int i=0;i<=n;i++){
        dp3[i] = 1e9;
    }
    dp3[u] = 0;
    
    while(!q1.empty()){
        auto hold = q1.top();
        int dist = -1*hold.first;
           q1.pop();
        int from = hold.second;
        
        if(from == v){
           // cout<<dist<<endl;
            return dist;
        }
        for(auto x:s1[from]){
            int to = x.first;
            int w = x.second;
            if(dp3[to]>dp3[from]+w){
                dp3[to] = dp3[from]+w;
                q1.push(make_pair(-1*dp3[to],to));
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            s1[x].insert(make_pair(y,w));
            s1[y].insert(make_pair(x,w));
            edges.push_back(make_pair(x,make_pair(y,w)));
        }
        for(int i=0;i<=n;i++){
            dp[i] = 1e9;
            dp2[i] = 1e9;
        }
        dijkstras();
        dijkstras2();
        
         while(q--){
            int i;
            cin>>i;
            int from = edges[i].first;
            int to = edges[i].second.first;
            int weight = edges[i].second.second;
            
            
            if(dp[from]+dp2[to]+weight!=dp[n-1]){
                cout<<"no route for corrupt ministers!!!"<<endl;
                continue;
            }else{
                s1[from].erase(make_pair(to,weight));
                s1[to].erase(make_pair(from,weight));
                int ans =dijkstras3(0,n-1);
                if(ans !=-1){
                    ans+=dp[from];
                }else{
                    cout<<"no route for corrupt ministers!!!"<<endl;
                    continue;
                }
                cout<<ans<<endl;
                s1[from].insert(make_pair(to,weight));
                s1[to].insert(make_pair(from,weight));
            }
        }
    }
}
