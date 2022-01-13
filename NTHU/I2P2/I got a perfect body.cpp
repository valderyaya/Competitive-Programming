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

ll t,n,p,k,a[300005],ans,dp[300005];
signed main(){Aincrad
	cin>>t;
	while(t--){
		cin>>n>>p>>k;
		REP1(i,1,n) cin>>a[i];
		sort(a+1,a+1+n);
		ans=0;
		REP1(i,1,n){
			if(i>=k) dp[i]=a[i]+dp[i-k];
			else dp[i]=a[i]+dp[i-1];
			if(dp[i]<=p) ans=i;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
