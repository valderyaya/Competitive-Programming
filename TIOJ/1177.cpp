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

int n,m,a[1001][1001],sx,sy,ex,ey,dx[]={1,0,0,-1},dy[]={0,1,-1,0};
int solve(){
    int x,y,xx,yy; a[sx][sy]=1;
    queue<pii> q; q.emplace(mkp(sx,sy));
    while(!q.empty()){
        tie(x,y)=q.front();q.pop();
        REP(i,4){
            xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||y>n||a[xx][yy]) continue;
            a[xx][yy]=a[x][y]+1; q.emplace(mkp(xx,yy));
        }
    }
    return a[ex][ey]?a[ex][ey]-1:-1;
}
int main(){Rosario
    cin>>n>>m;int x,y;
    while(m--) cin>>x>>y,a[x][y]=-1;
    cin>>sx>>sy>>ex>>ey;
    if(a[sx][sy]==-1||a[ex][ey]==-1) return cout<<-1,0;
    cout<<solve();
    return 0;
}
