#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
const int MAXN = 1010;
int dp[MAXN][MAXN];
vector<pair<int,int>> v1;
int ans;

int main() {
    ifstream fin("Pogo-Cow.in");
    ofstream fout("Pogo-Cow.out");
    int n;
    fin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        fin>>x>>y;
        v1.push_back(make_pair(x,y));
        
    }
    sort(v1.begin(),v1.end());
    int num = 2;
    while(num--){
        
        for(int i = n-1;i>=0;i--){
            int k = n;
            int temp = 0;
            for(int j=0;j<=i;j++){
                while(k-1>i && v1[k-1].first - v1[i].first >= v1[i].first - v1[j].first){
                    k--;
                    temp = max(temp,v1[k].second + dp[k][i]);
                }
                
                dp[i][j] = temp;
               // fout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
            ans = max(ans,v1[i].second + temp);
            fout<<ans<<endl;
        }
        for(int i=0;i<n;i++){
            v1[i].first = -v1[i].first;
        }
        reverse(v1.begin(),v1.end());
        for(int i=0;i<n;i++){
          //  fout<<v1[i].first<<" ";
        }
    }
    fout<<ans<<endl;
}
