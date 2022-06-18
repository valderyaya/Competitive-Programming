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


int a[505][505],d[505][505],dx[]={1,0,0,-1},ans[100005],dy[]={0,1,-1,0},n,m,c,b;
map<pii,int> ma;
queue<pii> q;
void solve(){
    int x,y,xx,yy;
    while(!q.empty()){
        tie(x,y)=q.front();q.pop();
        REP(i,4){
            xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m||d[xx][yy]==1||d[xx][yy]==-1) continue;
            a[xx][yy]=a[x][y]+1;
            if(d[xx][yy]==-2) ans[ma[{xx,yy}]]=a[xx][yy];
            q.emplace(mkp(xx,yy)); d[xx][yy]=1;
        }
    }
    REP(i,b) cout<<ans[i]<<"\n";
}
int main(){Rosario
    cin>>n>>m>>c>>b;
    int x,y;
    REP(i,c) cin>>x>>y,d[x][y]=-1,q.emplace(mkp(x,y));
    REP(i,b) {
        cin>>x>>y;
        if(d[x][y]==-1) continue;
        ma[{x,y}]=i; d[x][y]=-2;
    }
    solve();
    return 0;
}
