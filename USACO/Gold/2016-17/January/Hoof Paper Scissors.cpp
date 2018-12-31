#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int MAXN = 1000000;
map<pair<int,int>,int> m1;
map<pair<int,int>,int> m2;
vector<int> arrx[MAXN];
vector<int> arry[MAXN];

int main(){
    int n,x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arrx[x].push_back(y);
        arry[y].push_back(x);
    }
    queue<pair<pair<int,int>,int > > q1;
    q1.push(make_pair(make_pair(x1,y1),0));
    m2[make_pair(x1,y1)] = 0;
    while(!q1.empty()){
        int currx = q1.front().first.first;
        int curry = q1.front().first.second;
        int currdist = q1.front().second;
        cout<<currx<<" "<<curry<<" "<<currdist<<endl;
        q1.pop();
        if(currdist == 0){
            for(int z:arry[curry]){
                if(m1[make_pair(z,curry)] == 0){
                    m1[make_pair(z,curry)] = m2[make_pair(currx,curry)]+1;
                    q1.push(make_pair(make_pair(z,curry),1));
                }else if(m1[make_pair(z,curry)]>m2[make_pair(currx,curry)]+1){
                    m1[make_pair(z,curry)] = m2[make_pair(currx,curry)]+1;
                    q1.push(make_pair(make_pair(z,curry),1));
                }
            }
        }else{
            for(int z:arrx[currx]){
                if(m2[make_pair(currx,z)] == 0){
                    m2[make_pair(currx,z)] = m1[make_pair(currx,curry)]+1;
                    q1.push(make_pair(make_pair(currx,z),0));
                }else if(m2[make_pair(currx,z)]>m1[make_pair(currx,curry)]+1){
                   m2[make_pair(currx,z)] = m1[make_pair(currx,curry)]+1;
                   q1.push(make_pair(make_pair(currx,z),0));
                }
            }
        }
    }
      int tempans = 1000000000;
    for(int i=0;i<=1000000;i++){
        if(m2[make_pair(i,y2)]){
            tempans = min(tempans,m2[make_pair(i,y2)]);
        }
        if(m1[make_pair(x2,i)]){
            tempans = min(tempans,m1[make_pair(x2,i)]);
        }
    }


        m1.clear();
        m2.clear();
        q1.push(make_pair(make_pair(x1,y1),1));
         m1[make_pair(x1,y1)] = 0;
        while(!q1.empty()){
            int currx = q1.front().first.first;
            int curry = q1.front().first.second;
            int currdist = q1.front().second;
            q1.pop();
            if(currdist == 0){
                for(int z:arry[curry]){
                    if(m1[make_pair(z,curry)] == 0){
                        m1[make_pair(z,curry)] = m2[make_pair(currx,curry)]+1;
                        q1.push(make_pair(make_pair(z,curry),1));
                    }else if(m1[make_pair(z,curry)]>m2[make_pair(currx,curry)]+1){
                        m1[make_pair(z,curry)] = m2[make_pair(currx,curry)]+1;
                        q1.push(make_pair(make_pair(z,curry),1));
                    }
                }
            }else{
                for(int z:arrx[currx]){
                    if(m2[make_pair(currx,z)] == 0){
                        m2[make_pair(currx,z)] = m1[make_pair(currx,curry)]+1;
                        q1.push(make_pair(make_pair(currx,z),0));
                    }else if(m2[make_pair(currx,z)]>m1[make_pair(currx,curry)]+1){
                       m2[make_pair(currx,z)] = m1[make_pair(currx,curry)]+1;
                       q1.push(make_pair(make_pair(currx,z),0));
                    }
                }
            }
        }
    for(int i=0;i<=1000000;i++){
        if(m2[make_pair(i,y2)]){
            tempans = min(tempans,m2[make_pair(i,y2)]);
        }
        if(m1[make_pair(x2,i)]){
            tempans = min(tempans,m1[make_pair(x2,i)]);
        }
    }
    if(tempans = 1000000000){
        cout<<-1;
    }else{
        cout<<tempans;
    }
}
