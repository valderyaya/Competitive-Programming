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

int n,m,d[51][51];
bool dp[51][51][65];
int main(){Rosario
    cin>>n>>m;
    int x,y;
    REP1(i,1,n) REP1(j,1,n) d[i][j]=1e9;
    while(m--) cin>>x>>y,d[x][y]=1,dp[x][y][0]=1;
    REP1(l,1,64) REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) if(dp[i][k][l-1]&&dp[k][j][l-1]) dp[i][j][l]=1,d[i][j]=1;
    REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    cout<<d[1][n]<<"\n";
    return 0;
}
