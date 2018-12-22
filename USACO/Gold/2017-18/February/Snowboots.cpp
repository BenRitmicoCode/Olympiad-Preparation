#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const int MAXN = 100100;
int snow[MAXN];
int depth[MAXN];
int first[MAXN];
int step[MAXN];
int second[MAXN];
int pre[MAXN];
int nxt[MAXN];
bool ans[MAXN];
int curr[MAXN];
bool cmp(int a,int b){
    return depth[a]<depth[b];
}
bool cmp2(int a, int b){
    return snow[a]<snow[b];
}
int n,b;
int main() {
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
	fin>>n>>b;
	for(int i=0;i<n;i++){
	    fin>>depth[i];
	    first[i] = i;
	}
	for(int i=0;i<b;i++){
	    fin>>snow[i]>>step[i];
	    second[i] = i;
	    //fout<<second[i]<<endl;
	}
	sort(first,first+n,cmp);
	sort(second,second+b,cmp2);
	for(int i=0;i<n;i++){
	    if(i<b){
	        //fout<<second[i]<<endl;
	    }
	    pre[i] = i-1;
	    nxt[i] = i+1;
	}
	int steps = 1;
	int pointer = n-1;
	for(int i=b-1;i>=0;i--){
	    int curr= second[i];
	  //  fout<<second[b]<<endl;
	    while(pointer>=0 && snow[curr]<depth[first[pointer]]){
	        int now = first[pointer];
	        nxt[pre[now]] = nxt[now];
	        pre[nxt[now]] = pre[now];
	        steps = max(steps,nxt[now]-pre[now]);
	        pointer--;
	    }
	    ans[curr] = (steps<=step[curr]);
	}
	for(int i=0;i<b;i++){
	    fout<<ans[i]<<endl;
	}
}
