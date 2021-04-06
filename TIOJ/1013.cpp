//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

string f[]={
    "*****************",
    "*...*.......**..*",
    "**..*....*.*.*..*",
    "*......*.**.**.**",
    "*..**...**..**.**",
    "**.....**..*.*..*",
    "*....*..........*",
    "*.....****.*...**",
    "****.*.*........*",
    "*****************"};
int a[10][17]={},b[10][17]={},fx,fy,sx,x,y,xx,yy,sy,ex,ey,tim,dx[]={1,0,0,-1},dy[]={0,-1,1,0};
queue<int> q;
int main(){Rosario
    cin>>fx>>fy>>tim>>sx>>sy>>ex>>ey;f[ex][ey]='E';
    if(sx==ex&&sy==ey){
      cout<<"0\n";
      return 0;
    }
    q.emplace(fx);
    q.emplace(fy);
    a[fx][fy]=1;
    while(!q.empty()){
        x=q.front();q.pop();y=q.front();q.pop();
        REP(i,4){
            xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>9||yy<0||yy>16||f[xx][yy]=='*'||f[xx][yy]=='E'||a[xx][yy])continue;
            a[xx][yy]=a[x][y]+1;
            q.emplace(xx);q.emplace(yy);
        }
    }
    q.emplace(sx);
    q.emplace(sy);
    b[sx][sy]=tim;
    //REP(i,10) REP(j,17) cout<<a[i][j]<<" \n"[j==16];
    if(tim<a[sx][sy]){
        while(!q.empty()){
            int x=q.front();q.pop();y=q.front();q.pop();
            REP(i,4){
                xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>9||yy<0||yy>16||f[xx][yy]=='*'||b[xx][yy]||(b[x][y]+1>=a[xx][yy]&&f[xx][yy]!='E')) continue;
                q.emplace(xx);q.emplace(yy); b[xx][yy]=b[x][y]+1;
            }
        }
    }
    //REP(i,10) REP(j,17) cout<<b[i][j]<<" \n"[j==16];
    if(b[ex][ey]) cout<<b[ex][ey]-tim<<"\n";
    else cout<<"Help!\n";
    return 0;
}
