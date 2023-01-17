#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
 
ll a[20],b[20],n,m,ans,g;
vector<ll> s1,s2;
signed main(){valder
	cin>>n>>g; m=n-n/2, n/=2;
	REP(i,n) cin>>a[i];
	REP(i,m) cin>>b[i];
	for(int i=0;i<(1<<n);++i){
		ll s=0;
		for(int j=0;j<n;++j) if(i>>j&1) s+=a[j];
		s1.em(s);
	}
	for(int i=0;i<(1<<m);++i){
		ll s=0;
		for(int j=0;j<m;++j) if(i>>j&1) s+=b[j];
		s2.em(s);
	}
	sort(ALL(s1)); sort(ALL(s2));
	for(auto &i:s1) ans+=upper_bound(ALL(s2),g-i)-lower_bound(ALL(s2),g-i);
	cout<<ans<<"\n";
	return 0;
}
