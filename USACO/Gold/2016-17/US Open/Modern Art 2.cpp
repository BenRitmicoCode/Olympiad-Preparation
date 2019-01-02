#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
bool dp[100100];
int maxc[100100];
int colour[100100];
int main() {
    ifstream fin("art2.in");
    ofstream fout("art2.out");
	int n;
	fin>>n;
	for(int i=1;i<=n;i++){
	    fin>>colour[i];
	    maxc[colour[i]] = i;
	}
	int tempans = 0;
	dp[0] = true;
	vector<int> v1;
	v1.push_back(0);
	int ans = 0;
	for(int i=1;i<=n;i++){
	    if(dp[colour[i]] && v1[v1.size()-1]!=colour[i]){
	        fout<<-1<<endl;
	        return 0;
	    }
	    if(!dp[colour[i]]){
	        dp[colour[i]] = true;
	        v1.push_back(colour[i]);
	        tempans++;
	    }
	    ans = max(tempans,ans);
	    if(maxc[colour[i]] == i && colour[i]!=0){
	        dp[colour[i]] = false;
	        v1.pop_back();
	        tempans--;
	    }
	   // fout<<tempans<<endl;
	}
	fout<<ans<<endl;
}
