#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
int dp[3][410][410][410];
int cnt[3][410];
int a[450];
vector<int> col[3];
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i] == 'R'){
            a[i+1] = 0;
        }else if(s[i] == 'G'){
            a[i+1] = 1;
        }else{
            a[i+1] = 2;
        }
    }
    col[0].push_back(0);
	col[1].push_back(0);
	col[2].push_back(0);
	
	for(int i=1;i<=n;i++){
	    for(int j=0;j<3;j++){
	        cnt[j][i] = cnt[j][i-1];
	    }
	    //stores the number of colours encountered up to a certain position
	    cnt[a[i]][i]++;
	    //stores the positions of each colour
	    col[a[i]].push_back(i);
	}
	int R = col[0].size()-1;
	int G = col[2].size()-1;
	int B = col[1].size()-1;
	
	for(int last = 0; last < 3; last++){
		for(int r = 0; r <= R; r++){
			for(int b = 0; b <= B; b++){
				for(int g = 0; g <= G; g++){
					dp[last][r][b][g] = inf;
				}
			}
		}
	}
	dp[0][0][0][0] = 0;
	dp[1][0][0][0] = 0;
	dp[2][0][0][0] = 0;
	
	for(int r=0;r<=R;r++){
	    for(int b=0;b<=B;b++){
	        for(int g=0;g<=G;g++){
	            for(int last = 0;last<3;last++){
	                int ans = dp[last][r][b][g];
	                int c[3];
	                c[0] = r;
	                c[1] = b;
	                c[2] = g;
	                //c[i] = number of ith colour grasses we've encountered as of now
	                for(int i=0;i<3;i++){
	                    if(col[i].size()<=c[i]+1||last == i){
	                        continue;
	                    }
	                    //i = current colour
	                    int pos = col[i][c[i]+1];
	                    int tot = -1;
	                    for(int x =0;x<3;x++){
	                        //actual last encounter 
	                        int prev = col[x][c[x]];
	                        tot+=max(0,cnt[x][pos]-cnt[x][prev]);
	                    }
	                    c[i]++;
	                    dp[i][c[0]][c[1]][c[2]] = min(dp[i][c[0]][c[1]][c[2]],tot+ans);
	                    c[i]--;
	                }
	            }
	        }
	    }
	}
	int ans = inf;
	for(int i=0;i<3;i++){
	    ans = min(ans,dp[i][R][B][G]);
	}
	if(ans == inf){
	    cout<<-1;
	}else{
	    cout<<ans<<endl;
	}
	
}
