#include <iostream>

using namespace std;
const int MAXN = 1050;

int a[MAXN][MAXN];
int t[5*MAXN][5*MAXN];
int n,m;
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}
int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         + sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         + sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}
void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx){
            t[vx][vy] = new_val;
           // cout<<vx<<" "<<vy<<" "<<new_val<<endl;
        }else{
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
            if(new_val == -1){
              //  cout<<lx<<" "<<rx<<" "<<vx<<" "<<vy<<" "<<new_val<<endl;
            }
        }
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}
int main() {

    int num = -1;
    while(num!=3){
        cin>>num;
        
        if(num == 0){
            cin>>n;
            m = n;
           // cout<<n<<" "<<m<<endl;
            build_x(1,0,n-1);
            continue;
        }
        if(num == 1){
            int x,y,z;
            cin>>x>>y>>z;
            
           // cout<<z+a[x][y]<<endl;
            
            update_x(1,0,n-1,x,y,z+a[x][y]);
            a[x][y] += z;
           // cout<<sum_x(1,0,n-1,0,3,0,3)<<endl;
        }
        if(num == 2){
            
            int x,y,l,r;
            
            cin>>x>>y>>l>>r;
          
            
            cout<<sum_x(1,0,n-1,x,l,y,r)<<endl;
        }
    }
     
}
