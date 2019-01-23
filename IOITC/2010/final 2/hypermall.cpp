#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v1;
int main(){
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        v1.push_back(make_pair(x,y));
    }
    sort(v1.begin(),v1.end());
    set<int> s1;
    for(int i=0;i<n;i++){
        if(s1.size()<c){
            s1.insert(v1[i].first+v1[i].second);
           // cout<<*s1.begin()<<endl;
        }else{
            int hold = *s1.begin();
            
            s1.erase(s1.begin());
            s1.insert(v1[i].second+hold);
        }
        if(i<n-1 && v1[i+1].first>*s1.begin()){
             s1.erase(s1.begin());
        }
    }
    auto it = s1.end();
    it--;
    cout<<*it<<endl;
    
}
