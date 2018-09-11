#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long b[n+1];
    long long ans = 0;
    int second = 23;
    long long ind = 0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        
        if(b[i]>ans){
            ans = b[i];
            ind = i;
           
        }
    }
    if(b[n-1] == b[ind] && ind == 0){
        ind = n-1;
        while(b[ind] == b[0]){
            if(b[ind-1] == b[0] && ind>0){
                ind--;
            }else{
                break;
            }
            
        }
    }
    long long a[n+1];
    long long store = b[0];
    long long test = 1;
    for(int i=1;i<n;i++){
        if(b[i] != store){
            test = 23;
            break;
        }
    }
    if(test == 1){
        if(store == 0){
            std::cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                std::cout<<1<<" ";
            }
            return 0;
        }
        std::cout<<"NO"<<endl;
        return 0;
    }
    
    a[ind] = ans;
    for(int i=ind-1;i>=0;i--){
        if(b[i] == 0 && i == ind -1){
            a[i] = 2*b[i+1];
            continue;
        }
        a[i] = a[i+1]+b[i];
    }
    if(ind < n-1){
        a[n-1] = a[0] +b[n-1];
        if(ind == 0 && b[n-1] == 0){
            a[n-1] = b[0]*2;
        }
        //std::cout<<a[n-1];
        for(int i=n-2;i>ind;i--){
            a[i] = a[i+1]+b[i];
        }
    }
    std::cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        
        std::cout<<a[i]<<" ";
    }
}
