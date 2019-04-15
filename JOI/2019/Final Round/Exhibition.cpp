#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
   int n,m;
   const int MAXN = 100100;
   pair<int,int> v1[MAXN];
   int arr[MAXN];
bool check(int x){
    vector<int> v2;
    for(int i=m;i>(m-x);i--){
        v2.push_back(arr[i]);
    }
    for(int i=1;i<=n;i++){
        if(v2.empty()){
            return true;
        }
        if(v1[i].second<=v2.back()){
            v2.pop_back();
        }
    }
    if(v2.empty()){
        return true;
    }
    return false;
}
int main(){
 
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin>>v1[i].second>>v1[i].first;
    }
    for(int i=1;i<=m;i++){
        cin>>arr[i];
    }
    sort(v1+1,v1+1+n);
    sort(arr+1,arr+1+m);
    int l= 0;
    int r = m;
    int ans = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<ans<<endl;
}
