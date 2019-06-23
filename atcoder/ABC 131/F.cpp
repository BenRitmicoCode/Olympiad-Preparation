#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int MAXN = 2e5+5;
vector<int> v1x[MAXN];
int n;
vector<int> v1y[MAXN];
int x[MAXN];
int y[MAXN];
bool found[MAXN];
bool visx[MAXN];
bool visy[MAXN];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        v1x[x[i]].push_back(i);
        v1y[y[i]].push_back(i);
    }
    long long ans = -1*n;
    for(int i=1;i<=n;i++){
        if(found[i]){
            continue;
        }
        set<int> usedx,usedy;
        queue<int> q1;
        usedx.insert(x[i]);
        usedy.insert(y[i]);
        q1.push(i);
       
        while(!q1.empty()){
            int curr = q1.front();
            q1.pop();
            vector<int> tovisit;
            if(!visx[x[curr]]){
                visx[x[curr]]= true;
                for(int j:v1x[x[curr]]){
                    tovisit.push_back(j);
                }
            }
            
            if(!visy[y[curr]]){
                visy[y[curr]] = true;
                for(int j:v1y[y[curr]]){
                    tovisit.push_back(j);
                }
            }
            for(int j:tovisit){
                if(found[j]){
                    continue;
                }
                found[j] = true;
                usedx.insert(x[j]);
                usedy.insert(y[j]);
                q1.push(j);
            }
            
        }
        ans+=(long long)usedx.size()*(long long)usedy.size();
    }
    cout<<ans<<endl;
}
