#include<iostream>
#include<vector>
#include<algorithm>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> cur;
int arr[500001];
pair<int,int> check[500001];
long long ans = 0;
int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
	int n;
	fin>>n;
	for(int i=0;i<=500000;i++){
	    check[i].first = -1;
	    check[i].second = -1;
	}
	for(int i=0;i<2*n;i++){
	    int x;
	    fin>>x;
	    arr[i] = x;
	    if(check[x].first!=-1){
	        check[x].second = i;
	    }else{
	        check[x].first = i;
	    }
	}
	for(int i=0;i<2*n;i++){
	    if(i==check[arr[i]].first){
	        ans+=cur.order_of_key(check[arr[i]].second);
	        cur.insert(check[arr[i]].second);
	    }else{
	        cur.erase(check[arr[i]].second);
	    }
	}
	fout<<ans<<endl;
}
