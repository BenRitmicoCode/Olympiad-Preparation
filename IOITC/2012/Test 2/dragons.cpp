#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 310;
vector<pair<int,int>> v1;
int dp[MAXN][MAXN];
int main(){
    int r,k,c,d;
    cin>>r>>c>>k>>d;
    for(int i=0;i<d;i++){
        int x,y;
        cin>>x>>y;
        v1.push_back(make_pair(x,y));
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<=d;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = 1e9;
        }
    }
    for(int i=0;i<d;i++){
        dp[i][1] = abs(v1[i].first+v1[i].second);
    }
    for(int i=0;i<d;i++){
        for(int j=2;j<=k;j++){
            for(int x=0;x<i;x++){
                if(x == i){
                    continue;
                }
                dp[i][j] = min(dp[i][j], dp[x][j-1]+abs(v1[i].first-v1[x].first)+abs(v1[i].second-v1[x].second));
               // cout<<i<<" "<<v1[0].first<<endl;
            }
        }
    }
    int ans = 1e9;
    for(int i=0;i<d;i++){
        ans = min(ans,dp[i][k]);
    }
    cout<<ans<<endl;
}
