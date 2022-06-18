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
 
const ll md=998244353;
ll n,m,k,dp[2][2];
signed main(){Aincrad
	ll x1,x2,y1,y2;
	cin>>n>>m>>k>>x1>>y1>>x2>>y2;
	dp[x1==x2][y1==y2]=1;
	REP1(i,1,k){
		ll f[2][2]={};
		f[1][1]=(dp[1][0]+dp[0][1])%md;
		f[1][0]=(dp[0][0]+dp[1][0]*(m-2)+dp[1][1]*(m-1))%md;
		f[0][1]=(dp[0][0]+dp[0][1]*(n-2)+dp[1][1]*(n-1))%md;
		f[0][0]=(dp[1][0]*(n-1)+dp[0][1]*(m-1)+dp[0][0]*(n+m-4))%md;
		memcpy(dp,f,sizeof(dp));
	}
	cout<<dp[1][1]<<"\n";
	return 0;
}
