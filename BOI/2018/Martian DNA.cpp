#include <iostream>
#include <map>
using namespace std;
const int MAXN = 2e5+5;
int arr[MAXN];

map<int,int> m1;
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        m1[x] = y;
    }
    int j=1;
    int ans = 1e9;
    int l = q;
    for(int i=1;i<=n;i++){
        while(l && j<=n){
            m1[arr[j]]--;
            if(m1[arr[j]] == 0){
                l--;
            }
            j++;
            
        }
        if(!l){
            ans = min(ans,j-i);
        }
        m1[arr[i]]++;
        if(m1[arr[i]] == 1){
            l++;
        }
        
    }
    if(ans == 1e9){
        cout<<"impossible"<<endl;
        return 0;
    }
    cout<<ans<<endl;
}
