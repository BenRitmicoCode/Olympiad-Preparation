#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v1;
int n = 2;
vector<pair<int,int>> arr[25];
int len = 0;
int m;
void mult(){
    for(int i=1;i<=20;i++){
        for(auto &x:arr[i]){
            x.second*=2;
        }
    }
    arr[n].push_back(make_pair(n+1,0));
    arr[n].push_back(make_pair(n+1,1));
    m+=2;
    n++;
    len*=2;
}
void add(){
    arr[1].push_back(make_pair(n,len++));
    m++;
}
int main() {
	int l;
	cin>>l;
	while(l){
	    v1.push_back(l%2);
	    l/=2;
	}
	reverse(v1.begin(),v1.end());
	for(int i=0;i<v1.size();i++){
	    if(i==0){
	        if(v1[i]){
	            add();
	        }
	        continue;
	    }
	    if(len!=1){
	        mult();
	    }
	    if(len==1){
	        add();
	    }
	    if(v1[i]){
	       add();
	    }
	}
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=20;i++){
	    for(auto x:arr[i]){
	        cout<<i<<" "<<x.first<<" "<<x.second<<endl;
	    }
	}
}
