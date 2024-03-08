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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
ll n,m,q,dp[505][505];
signed main(){Aincrad
	cin>>n>>m>>q;
	REP1(i,1,n) REP1(j,1,n) if(i!=j) dp[i][j]=1e18;
	for(ll x,y,z;m;--m) cin>>x>>y>>z,dp[x][y]=dp[y][x]=min(dp[x][y],z);
	REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(ll x,y;q;--q){
		cin>>x>>y;
		if(dp[x][y]==1e18) cout<<"-1\n";
		else cout<<dp[x][y]<<"\n";
	}
	return 0;
}
