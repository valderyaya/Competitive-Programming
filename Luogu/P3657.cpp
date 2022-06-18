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
#define lb(x) (x&-x)

const int z=1e5+5;
int n,a[z],pos[z];
vector<int> v,p,ans;
signed main(){Rosario
	cin>>n;
	REP1(i,1,n) cin>>a[i];
	for(int x,i=1;i<=n;++i) cin>>x,pos[x]=i;
	REP1(i,1,n){
		p.clear();
		for(int j=max(1,a[i]-4);j<=min(n,a[i]+4);++j) p.em(pos[j]);
		sort(ALL(p),greater<int>());
		for(auto &j:p) v.em(j);
	}
	REP(i,v.size()){
		if(ans.empty()||ans.back()<v[i]) ans.em(v[i]);
		else ans[lower_bound(ALL(ans),v[i])-ans.begin()]=v[i];
	}
	cout<<ans.size()<<"\n";
	return 0;
}
