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

int n,m,ans,dx[]={0,1,0,-1},c[1005][1005],dy[]={1,0,-1,0};
string a[1005];
queue<pii> q;
bool out(int x,int y){
    return x<0||x>=n||y<0||y>=m;
}
signed main(){Alicization
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    REP(i,n) REP(j,m) if(a[i][j]=='I'){
        q.emplace(i,j); c[i][j]=1;
        int x,y;
        while(!q.empty()){
            tie(x,y)=q.front(); q.pop();
            if(a[x][y]=='T') ans=max(ans,c[x][y]-1);
            REP(k,4){
                int xx=x+dx[k],yy=y+dy[k];
                if(out(xx,yy)||c[xx][yy]||a[xx][yy]=='C') continue;
                c[xx][yy]=c[x][y]+1;
                q.emplace(xx,yy);
            }
        }
    }
    REP(i,n) REP(j,m) if(a[i][j]=='T'&&!c[i][j]) return cout<<"-1\n",0;
    cout<<ans<<'\n';
    return  0;
}
