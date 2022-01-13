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

ll t,n,m,sum,a[200005];
ll cal(ll x){
	ll ret=0;
	REP(i,n) ret+=max(0LL,a[i]-i/x);
	//cout<<x<<' '<<ret<<endl;
	return ret;
}
signed main(){Aincrad
	cin>>t;
	while(t--){
		cin>>n>>m;
		sum=0;
		REP(i,n) cin>>a[i],sum+=a[i];
		if(sum<m){
			cout<<"-1\n";
			continue;
		}
		ll mid,l=0,r=n-1;
		while(l<r){
			mid=l+r>>1;
			if(cal(mid+1)<m) l=mid+1;
			else r=mid;
		}
		cout<<1+l<<"\n";
	}
	return 0;
}
