#include <iostream>

using namespace std;
int p,q,n;
int dp[110][210][1001];
int h[110];
int g[110];
int rec(int curr,int health,int extrashots){
    if(health<=0 && curr == n){
        return 0;
    }
    if(health<=0){
        return rec(curr+1,h[curr+1],extrashots);
    }
    //cout<<curr<<endl;
    if(dp[curr][health][extrashots]!=-1){
        return dp[curr][health][extrashots];
    }
    
    int temp = rec(curr,health-q,extrashots+1);
    
    if(extrashots>0){
        if(health-p<=0){
            temp = max(temp,g[curr]+rec(curr,health-p,extrashots-1));
        }else{
            temp = max(temp,rec(curr,health-p,extrashots-1));
        }
    }
    if(p==20 && q == 147 && n==100){
       // cout<<curr<<endl;
    }
    return dp[curr][health][extrashots] = temp;
    
}
int main(){
    int t;
    cin>>t;
    int total = t;
    while(t--){
        for(int i=0;i<110;i++){
            for(int j=0;j<210;j++){
                for(int k=0;k<1001;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        cin>>p>>q>>n;
        //cout<<p<<" "<<q<<" "<<n<<endl;
        for(int i=1;i<=n;i++){
            cin>>h[i]>>g[i];
        }
        cout<<"Case #"<<total-t<<": "<<rec(1,h[1],1)<<endl;
        
    }
}
