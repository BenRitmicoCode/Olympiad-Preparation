#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
using namespace std;
int ans;
int elsie[100001];
int exists[100001];
vector<int> bessie;
int main() {
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
	    fin>>elsie[i];
	    exists[elsie[i]] = 1;
	}
	for(int i=1;i<=2*n;i++){
	    if(!exists[i]){
	        bessie.push_back(i);
	    }
	}
	sort(bessie.begin(),bessie.end());
	set<int> s1;
	for(int i=0;i<n/2;i++){
	    s1.insert(-1*bessie[i]);
	}
	set<int> s2;
	for(int i=n/2;i<n;i++){
	    s2.insert(bessie[i]);
	}
	for(int i=0;i<n/2;i++){
	    if(s2.lower_bound(elsie[i])!=s2.end()){
	        s2.erase(s2.lower_bound(elsie[i]));
	        ans++;
	    }
	}
	for(int i=n/2;i<n;i++){
	    auto hold = s1.lower_bound(-1*elsie[i]);
	    
	    if(hold!=s1.end()){
	        s1.erase(hold);
	        ans++;
	    }
	}
	fout<<ans<<endl;
}
