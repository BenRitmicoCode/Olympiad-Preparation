#include <iostream>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int line = 0;
	while(n--){
	    int t;
	    cin>>t;
	    if(line>0){
	        t-=(m-line);
	    }
	    //std::cout<<t<<" !";
	    if(t>0){
    	    int turn = t/m;
    	    if(line>0){
    	        //std::cout<<turn<<endl;
    	        turn++;
    	    }
    	    line = t%m;
    	    //std::cout<<line<<endl;
    	    std::cout<<turn<<" ";
	    }
	    else if(t<0){
	        std::cout<<0<<" ";
	        line = line+t+(m-line);
	    }else{
	        std::cout<<1<<" ";
	        line = 0;
	    }
	}
}
