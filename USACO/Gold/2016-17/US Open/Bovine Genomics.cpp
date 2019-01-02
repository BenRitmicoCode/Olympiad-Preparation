#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
map<string,int> m1;
int n,m;
const int MAXN = 1100;
string str[1100];
bool check(int x){
    
    for(int j=0;j<=m-x;j++){
        set<string> s1;
        set<string> s2;
        for(int i=0;i<n;i++){
            s1.insert(str[i].substr(j,x));
        }
         int curr = s1.size();
          for(int i=n;i<2*n;i++){
              s2.insert(str[i].substr(j,x));
          }
          bool ok = true;
          for(auto it = s1.begin();it!=s1.end();it++){
                if(s2.find(*it) != s2.end()){
                    ok = false;
                }
              }
          if(ok){
              return true;
          }
    }
   return false;
}
int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
	fin>>n>>m;
	
	for(int i=0;i<2*n;i++){
	    fin>>str[i];
	}
	int l = 1;
	int r = m;
	int ans = 0;
	while(l<=r){
	    int mid = (l+r)/2;
	    if(check(mid)){
	        r=mid-1;
	        ans = mid;
	    }else{
	        l=mid+1;
	    }
	   // fout<<mid<<" "<<ans<<endl;
	}
	fout<<ans<<endl;
}
