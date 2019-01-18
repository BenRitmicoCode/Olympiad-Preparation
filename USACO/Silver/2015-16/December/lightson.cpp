#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <fstream>
using namespace std;
bool on[1010][1010];
int dx[5] = {1,0,-1,0};
int dy[5] = {0,-1,0,1};

bool visited[1010][1010];
vector<pair<int,int>> lights[1010][1010];
set<pair<int,int>> badpoints;
int n,m;
bool check(int x,int y){
    return (x<=n && x>=1 && y<=n && y>=1);
}
void bfs2(int tempx,int tempy){
    deque<pair<int,int>> q1;
    q1.push_front(make_pair(tempx,tempy));
    while(!q1.empty()){
        auto hold = q1.front();
        int x = hold.first;
        int y = hold.second;
      // fout<<x<<" "<<y<<endl;
        q1.pop_front();
        if(visited[x][y]){
            continue;
        }
        
        if(!on[x][y]){
            continue;
        }
        visited[x][y] = true;
        for(auto z:lights[x][y]){
            //fout<<x<<" "<<y<<" "<<z.first<<" "<<z.second<<endl;
            on[z.first][z.second] = true;
            for(int i=0;i<4;i++){
                int currx = x+dx[i];
                int curry = y+dy[i];
                if(currx == z.first && curry == z.second){
                   bfs2(currx,curry);
                    
                }
            }
             if(badpoints.find(make_pair(z.first,z.second))!=badpoints.end()){
                    badpoints.erase(make_pair(z.first,z.second));
                    q1.push_back(make_pair(z.first,z.second));
                }
        }
        for(int i=0;i<4;i++){
            int currx = x+dx[i];
            int curry = y+dy[i];
            if(!check(currx,curry)){
                continue;
            }
           
        
            if(on[currx][curry]){
                if(!visited[currx][curry]){
                    q1.push_front(make_pair(currx,curry));
                }
            }else{
                    badpoints.insert(make_pair(currx,curry));
                }
        }
    }
}
int main(){
   ifstream fin("lightson.in");
   ofstream fout("lightson.out");
    fin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y,a,b;
        fin>>x>>y>>a>>b;
        lights[x][y].push_back(make_pair(a,b));
    }
    on[1][1] = true;

    deque<pair<int,int>> q1;
    q1.push_front(make_pair(1,1));
    while(!q1.empty()){
        auto hold = q1.front();
        int x = hold.first;
        int y = hold.second;
      // fout<<x<<" "<<y<<endl;
        q1.pop_front();
        if(visited[x][y]){
            continue;
        }
        
        if(!on[x][y]){
            continue;
        }
        visited[x][y] = true;
        for(auto z:lights[x][y]){
          //  fout<<x<<" "<<y<<" "<<z.first<<" "<<z.second<<endl;
            on[z.first][z.second] = true;
            for(int i=0;i<4;i++){
                int currx = x+dx[i];
                int curry = y+dy[i];
                if(currx == z.first && curry == z.second){
                    bfs2(currx,curry);
                    
                }
                
            }
            if(badpoints.find(make_pair(z.first,z.second))!=badpoints.end()){
                    badpoints.erase(make_pair(z.first,z.second));
                    q1.push_back(make_pair(z.first,z.second));
                }
        }
        for(int i=0;i<4;i++){
            int currx = x+dx[i];
            int curry = y+dy[i];
            if(!check(currx,curry)){
                continue;
            }
           
        
            if(on[currx][curry]){
                if(!visited[currx][curry]){
                    q1.push_front(make_pair(currx,curry));
                }
            }else{
                badpoints.insert(make_pair(currx,curry));
                
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(on[i][j]){
                ans++;
            }
        }
    }
    fout<<ans<<endl;
}
