//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int t,a[105][105],n,m,cnt[105][105],dx[]={1,0,0,-1},dy[]={0,1,-1,0};
queue<pii> q; 
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n>>m; 
        cnt[1][1]=0;
        REP1(i,1,n) REP1(j,1,m) cin>>a[i][j];
        while(!q.empty()) q.pop();
        q.emplace(mkp(1,1));
        while(!q.empty()){
            pii p=q.front(); q.pop();
            REP(i,4){
                int x=p.F+dx[i],y=p.S+dy[i];
                if(x<1||x>n||y<1||y>m||a[x][y]==-10||abs(a[x][y]-a[p.F][p.S])>5) continue;
                q.emplace(mkp(x,y)); 
                cnt[x][y]=cnt[p.F][p.S]+1;
            }
            a[p.F][p.S]=-10;
        }
        cout<<cnt[n][m]<<"\n";
    }
    return 0;
}
