#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
using namespace std;
const int MAXN = 1000010;
vector<pair<int,int>> places;
unordered_map<int,vector<int>> x, y;

int dp[MAXN][2];
int main(){
    ifstream fin("lasers.in");
    ofstream fout("lasers.out");
    int n,x1,y1,x2,y2;
    fin>>n>>x1>>y1>>x2>>y2;
    places.push_back(make_pair(x1,y1));
    for(int i=0;i<n;i++){
        int x,y;
        fin>>x>>y;
        places.push_back(make_pair(x,y));
    }
    places.push_back(make_pair(x2,y2));
    for(int i=0;i<places.size();i++){
        x[places[i].first].push_back(i);
        y[places[i].second].push_back(i);
    }
    queue<pair<int,int>> q1;
    q1.push(make_pair(0,0));
    q1.push(make_pair(0,1));
    for(int i=0;i<=1000000;i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    while(!q1.empty()){
        auto hold = q1.front();
        q1.pop();
        //fout<<hold.first<<" "<<hold.second<<endl;
        if(hold.first == places.size()-1){
            fout<<dp[hold.first][hold.second]-1<<endl;
            return 0;
        }
        
        if(hold.second == 0){
            for(int i:x[places[hold.first].first]){
              
                if(i!=hold.first && dp[i][1] == -1){
                    dp[i][1] = dp[hold.first][0]+1;
                    q1.push(make_pair(i,1));
                }
            }
        }else{
            for(int i:y[places[hold.first].second]){
                
                if(i!=hold.first && dp[i][0] == -1){
                     
                    dp[i][0] = dp[hold.first][1] + 1;
                    q1.push(make_pair(i,0));
                }
            }
        }
    }
    fout<<-1<<endl;
}
