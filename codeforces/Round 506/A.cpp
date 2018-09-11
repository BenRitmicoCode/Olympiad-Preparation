#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string a=s;
    int i = 0;
    int compress = 0;
    char store = s[i];
    int av = 23;
    for(int i=1;i<s.length();i++){
        if(s[i] == store){
            continue;
        }else{
            av = 45;
        }
    }
    if(av == 23){
        for(int i=1;i<k;i++){
            a+=store;
        }
        std::cout<<a<<endl;
        return 0;
    }
    while(i<n-1){
        //std::cout<<s.substr(0,i+1)<<" "<< s.substr(s.length()-1-i,i+1)<<endl;
       
        if(s.substr(0,i+1) == s.substr(s.length()-1-i,i+1)){
            compress= i+1;
            i++;
        }else{
             i++;
        }
    }
    
    //std::cout<<compress<<endl;
    for(int i=1;i<k;i++){
        for(int j=compress;j<s.length();j++){
            a+=s[j];
        }
    }
    std::cout<<a<<endl;
}
