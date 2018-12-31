#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream> 
#include <vector>
#include <fstream>
using namespace std;
using namespace __gnu_pbds;  


typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set;  
int main() {
    ifstream fin("bphoto.in");
    ofstream fout("bphoto.out");
	int n;
	fin>>n;
	ordered_set s1;
	ordered_set s2;
	vector<int> v1;
	int l[n+1];
	int r[n+1];
	for(int i=0;i<n;i++){
	    int x;
	    fin>>x;
	    v1.push_back(x);
	}
	l[0] = 0;
	s1.insert(v1[0]);
	for(int i=1;i<n;i++){
	    l[i] = i-s1.order_of_key(v1[i]+1);
	    s1.insert(v1[i]);
	}
	r[n-1] = 0;
	s2.insert(v1[n-1]);
	for(int i=n-2;i>=0;i--){
	    r[i] = n-1-i-s2.order_of_key(v1[i]+1);
	    s2.insert(v1[i]);
	}
	int ans =0;
	for(int i=0;i<n;i++){
	    if(l[i]>2*r[i]||r[i]>2*l[i]){
	        ans++;
	 //       fout<<v1[i]<<endl;
	    }
	}
	fout<<ans<<endl;
	
}
