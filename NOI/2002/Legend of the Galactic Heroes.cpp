#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 300100;
int sz[MAXN];
int par[MAXN];
int previ[MAXN];
int find(int a){
    if(par[a] == a){
        return a;
    }
    int hold = find(par[a]);
    previ[a] += previ[par[a]];
    return par[a] = hold;
}
void unite(int x,int y){
    int first = find(x);
    int second = find(y);
    par[first] = second;
    previ[first] = sz[second];
    //cout<<first<<" "<<previ[first]<<endl;
    sz[second]+=sz[first];
    
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=30000;i++){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        if(x== 'M'){
            int x,y;
            cin>>x>>y;
            unite(x,y);
            
        }else{
            int x,y;
            cin>>x>>y;
            if(find(x) == find(y)){
                
                cout<<abs(previ[x]-previ[y])-1<<endl;
            }else{
                cout<<-1<<endl;
            }
        }
    }
}
