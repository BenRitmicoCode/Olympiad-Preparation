#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 5e5+5;

vector<int> v1[MAXN];
vector<int> v2;
void dfs(int curr,int par){
    if(v1[curr].size() == 1){
        v2.push_back(curr);
    }
    for(int x:v1[curr]){
        if(x != par){
            dfs(x,curr);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
        
    }
    dfs(1,1);
    if(v2.size()%2 == 0){
        cout<<v2.size()/2<<endl;
        for(int i=0;i<v2.size()/2;i++){
            cout<<v2[i]<<" "<<v2[i+(v2.size()/2)]<<endl;
        }
    }else{
        cout<<(v2.size()/2)+1<<endl;
        for(int i=0;i<v2.size()/2;i++){
            cout<<v2[i]<<" "<<v2[i+(v2.size()/2)+1]<<endl;
        }
        cout<<v2[(v2.size())/2]<<" "<<1<<endl;
    }
}
