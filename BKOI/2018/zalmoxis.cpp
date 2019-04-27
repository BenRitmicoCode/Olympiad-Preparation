#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int> v1;
vector<int> ans;
set<int> s1;
int idx;
void solve(int curr,int level){
    if(v1[idx] == level){
        ans.push_back(curr);
        idx++;
        return;
    }
    solve(2*curr,level-1);
    if(idx == v1.size()||level<=v1[idx]){
        s1.insert(2*curr+1);
        return;
    }
    solve(2*curr+1,level-1);
}
void getans(int curr,int level){
    if(binary_search(ans.begin(),ans.end(),curr)){
        cout<<level<<" ";
        return;
    }
    getans(2*curr,level-1);
    getans(2*curr+1,level-1);
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v1.push_back(x);
    }
    solve(1,30);
    while(s1.size()<k){
        auto hold = *s1.begin();
        s1.erase(hold);
        s1.insert((hold)*2);
        s1.insert((hold)*2 +1);
    }
    for(auto i:s1){
        ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    getans(1,30);
}
