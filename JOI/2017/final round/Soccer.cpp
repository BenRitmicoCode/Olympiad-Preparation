#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
 
long long n,m,a,b,c,t;
long long dx[5] = {-1,0,1,0};
long long dy[5] = {0,1,0,-1};
long long dis[550][550];
long long dist[550][550][7];
priority_queue<pair<pair<long long,long long>,pair<long long,long long>>> pq;
bool check(long long x ,long long y){
    if(x<0||y<0||x>n||y>m){
        return false;
    }
    return true;
}
void insert(long long x,long long y,long long t,long long d){
    if(!check(x,y)){
        return;
    }
   
    if(dist[x][y][t]>d){
        dist[x][y][t] = d;
        pq.push(make_pair(make_pair(-1*d,t),make_pair(x,y)));
    }
}
int main() {
    cin>>n>>m>>a>>b>>c>>t;
    for(long long i=0;i<=n;i++){
        for(long long j=0;j<=m;j++){
            for(long long k=0;k<=5;k++){
                dist[i][j][k] = 1e18;
                dis[i][j] = 1e18;
            }
        }
    }
    queue<pair<long long,long long>> q1;
    pair<long long,long long> start,end;
    for(long long i=0;i<t;i++){
        long long x,y;
        cin>>x>>y;
        if(i == 0){
            start = make_pair(x,y);
        }
        if(i==t-1){
            end = make_pair(x,y);
        }
        dis[x][y] = 0;
        q1.push(make_pair(x,y));
        
        
    }
    while(!q1.empty()){
        auto x= q1.front();
      
        q1.pop();
        for(long long i=0;i<4;i++){
            if(check(x.first+dx[i],x.second+dy[i]) && dis[x.first+dx[i]][x.second+dy[i]]>1e9){
                dis[x.first+dx[i]][x.second+dy[i]] = dis[x.first][x.second]+1;
                q1.push(make_pair(x.first+dx[i],x.second+dy[i]));
            }
        }
    }
    insert(start.first,start.second,4,0);
    while(!pq.empty()){
        auto hold= pq.top();
        
        pq.pop();
        long long x = hold.second.first;
        long long y = hold.second.second;
        long long distance = -1*hold.first.first;
        long long t = hold.first.second;
        
        if(dist[x][y][t]!=distance){
            continue;
        }
        if(t==4){
            for(long long i=0;i<4;i++){
                insert(x+dx[i],y+dy[i],4,distance+c);
                insert(x,y,i,distance+b);
            }
        }else{
            insert(x+dx[t],y+dy[t],t,distance+a);
            insert(x,y,4,distance+dis[x][y]*c);
        }
    }
    cout<<dist[end.first][end.second][4]<<endl;
    
}
