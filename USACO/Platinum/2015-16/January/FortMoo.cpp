#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 210;
int l[MAXN][MAXN];
int u[MAXN][MAXN];
int main() {
    ifstream fin("fortmoo.in");
    ofstream fout("fortmoo.out");
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            fin>>c;
            if(j >0 && c=='.'){
                l[j][i] = l[j-1][i];
            }
            if(i>0 && c=='.'){
                u[j][i] = u[j][i-1];
            }
            if(c=='.'){
                l[j][i]++;
                u[j][i]++;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(l[j][i] == 0){
                continue;
            }
            for(int width=1;width<=l[j][i];width++){
                for(int height = min(u[j][i],u[j-width+1][i])+1;height>=1;height--){
                    if(l[j][i-height+1]>=width){
                        ans = max(ans,width*height);
                        break;
                    }
                }
            }
        }
    }
    fout<<ans<<endl;
}
