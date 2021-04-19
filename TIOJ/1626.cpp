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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

ll n,dp[1000005],fp=2;
ll f(ll l,ll r,ll v){
	++r;
	while(r-l>1){
		ll mid=l+r>>1;
		if(dp[mid]>=v) r=mid;
		else l=mid;
	}
	return ++l;
}
int main(){Rosario
	dp[1]=1;
	dp[2]=3;
	REP1(i,3,1000000) {
		//cout<<f(1,fp,i)<<" ";
		dp[i]=dp[i-1]+f(1,fp++,i);
		//cout<<dp[i]<<endl;
	}
	while(cin>>n,n) cout<<(n==1?1:f(1,fp,n))<<"\n";
	return 0;
}
