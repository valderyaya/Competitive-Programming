//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Alicization ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int a[1005][1005],n,m,p,q;
bool mp[1005][1005];
pii jk;
bool in(int x,int y){return (x>0&&x<=n&&y>0&&y<=m);}
int dx[8],dy[8];
int bfs(int stx,int sty,int edx,int edy){
    queue<pii> q;
    REP1(i,1,n) REP1(j,1,m) a[i][j]=0;
    q.emplace(stx,sty); a[stx][sty]=1;
    while(!q.empty()){
        auto [x,y]=q.front(); q.pop();
        REP(i,8){
            int xx=x+dx[i],yy=y+dy[i];
            if(in(xx,yy)&&!mp[xx][yy]&&!a[xx][yy]){
                a[xx][yy]=a[x][y]+1;
                q.emplace(xx,yy);
            }
        }
    }
    return a[edx][edy]?a[edx][edy]:1e9;
}
signed main(){Alicization
    cin>>n>>m>>p>>q>>jk.F>>jk.S;
    REP1(i,1,n) REP1(j,1,m) cin>>mp[i][j];
    dx[1]=q, dx[3]=-q, dx[5]=p, dx[7]=-p;
    dy[0]=q, dy[2]=-q, dy[4]=p, dy[6]=-p;
    // dx={0,q,0,-q,0,p,0,-p};
    // dy={q,0,-q,0,p,0,-p,0};
    int ans=bfs(1,1,jk.F,jk.S)+bfs(jk.F,jk.S,n,m);
    cout<<(ans>=1e9?-1:ans-2)<<'\n';
    return 0;
}
