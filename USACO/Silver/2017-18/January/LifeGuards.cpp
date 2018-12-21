#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v1;
set<int> s1;
const int MAXN = 100100;
int alone[MAXN];
int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
	    int x,y;
	    fin>>x>>y;
	    v1.push_back(make_pair(x,i));
	    v1.push_back(make_pair(y,i));
	}
	sort(v1.begin(),v1.end());
	int total = 0;
	int ans = 0;
	int last = 0;
	for(int i=0;i<v1.size();i++){
	    if(s1.size() == 1){
	        alone[*s1.begin()] = v1[i].first - last; //2
	    }
	    if(!s1.empty()){
	        total+=v1[i].first - last; // 2+1
	    }
	    if(s1.find(v1[i].second)!=s1.end()){
	        s1.erase(s1.find(v1[i].second));
	    }else{
	        s1.insert(v1[i].second);
	    }
	    last = v1[i].first;
	    
	}
//	fout<<total<<endl;
	
	for(int i=0;i<n;i++){
	  //  fout<<alone[i]<<endl;
	    ans = max(ans,total - alone[i]);    
	}
	fout<<ans<<endl;
}
