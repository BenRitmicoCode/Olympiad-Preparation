#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
vector<pair<int,int>> v1;

int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int n,k;
    fin>>n>>k;
    for(int i=0;i<n;i++){
        int x,y;
        fin>>x>>y;
        v1.push_back(make_pair(x,y));
        
    }
    sort(v1.begin(),v1.end());
    int l = -1;
    for(int i=0;i<v1.size();i++){
        if(v1[i].second<=l){
            v1.erase(v1.begin()+(i--));
        }
        l = v1[i].second;
    }
    int tempans = k - (n-v1.size());
    n = v1.size();
    int dp[n+5][k+5];
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=k+1;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = v1[0].second-v1[0].first;
    int curr = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<min(k+1,i+1);j++){
            int temp = 0;
            if(j>0){
                temp = dp[i-1][j-1];
            }
            temp = max(temp,v1[i].second-v1[i].first);
            while(v1[curr].second<v1[i].first){
                curr++;
            }
            if(i!=curr){
                temp = max(temp,dp[curr][max(0,j-i+curr+1)]+v1[i].second-v1[curr].second);
            }else{
                temp = max(temp,dp[i-1][j]+v1[i].second-v1[i].first);
            }
            if(curr>0){
                temp = max(temp,dp[curr-1][max(0,j-i+curr)]+v1[i].second-v1[i].first);
            }
            dp[i][j] = temp;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i][max(0,tempans)]);
    }
    fout<<ans<<endl;
}
