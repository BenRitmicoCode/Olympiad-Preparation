#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("chairsin.txt");
    ofstream fout("chairsout.txt");

	int c,n,k;
	fin>>c>>n>>k;
	int chairs[c+1];
	int count = 0;
	for(int i=0;i<c;i++){
	    char x;
	    fin>>x;
	    if(x=='w'){
	        chairs[i] = 0;
	    }else{
	        chairs[i] = 1;
	        count++;
	    }
	}
	int i=0,j=1;
	int ans = c;
	int dry = chairs[i]+chairs[j];
	while(j<c){
	    if(dry >= n-k && j-i+1 >= n){
	            
	        ans = min(ans, j-i+1);
	        //std::cout<<i<<" "<<j<<" "<<ans<<endl;
	        
	        dry -=chairs[i];
	        i+=1;
	        //std::cout<<dry<<endl;
	    }else{
	        if(j==c-1){
	            break;
	        }
	            j+=1;
	            dry+=chairs[j];
	    }
	}
	if(n==1 && count>0){
	    ans = 1;
	}
	fout<<ans;
}
