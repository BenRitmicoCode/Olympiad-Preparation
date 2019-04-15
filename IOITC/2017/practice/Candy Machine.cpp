#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v2;
vector<pair<int,int>> v1;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int s,t;
        cin>>s>>t;
        v1.push_back(make_pair(s+t,t-s));
        //cout<<s+t<<" "<<t-s<<endl;
        //ranges covered from either side
    }
    sort(v1.begin(),v1.end());
    for(int i=0;i<n;i++){
        if(v2.empty()||-1*v1[i].second>v2.back()){
            //cout<<v1[i].second<<endl;
            v2.push_back(-1*v1[i].second);
            
        }else{
            *lower_bound(v2.begin(),v2.end(),-1*v1[i].second) = -v1[i].second;
        }
    }
    cout<<v2.size()<<endl;
}
