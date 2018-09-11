#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
	int n;
	cin>>n;
	set<int> sell,buy,hold;
	long long  ans = 1;
	for(int i=0;i<n;i++){
	    //std::cout<<i<<" ";
	    string a;
	    int p;
	    cin>>a>>p;
	    
	   
	    
	    if(a.size() == 3){
	        
	        if(!buy.empty() && p<=*buy.rbegin()){
	            buy.insert(p);
	        }
	        else if( !sell.empty() && p>=*sell.begin()){
	            sell.insert(p);
	           
	        }else{
	            hold.insert(p);
	        }
	        
	    }else{
	        if( !buy.empty() && p<*buy.rbegin()){
	            std::cout<<0<<endl;
	            return 0;
	        }
	        else if( !sell.empty() && p>*sell.begin()){
	            std::cout<<0<<endl;
	            return 0;
	        }
	        
	        else if(buy.count(p)){
	            buy.erase(p);
	            for(int x: hold){
	                sell.insert(x);
	            }
	            hold.clear();
	        }
	        else if(sell.count(p)){
	            sell.erase(p);
	            for(int x: hold){
	                buy.insert(x);
	            }
	            hold.clear();
	        }
	        else{
	            hold.erase(p);
	            ans *=2;
	            ans%=(1000000007);
	            for(int x: hold){
	                if(x<p){
	                    buy.insert(x);
	                }
	                else{
	                    sell.insert(x);
	                }
	                
	            }
	            hold.clear();
	        }
	    }
	    
	}
	std::cout<<(ans*(hold.size()+1))%(1000000007)<<endl;
}
