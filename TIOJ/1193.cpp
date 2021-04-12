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

vector<ll> p;
ll n,m;
ll power(ll a,ll N){
	ll res=1;
	for(a%=m;N;N>>=1,a=a*a%m) if(N&1) res=res*a%m;
	return res;
}
bool vis[1000005];
void cal(){
	for(int i=2;i<1000000;++i){
		if(!vis[i]) p.em(i);
		for(auto &j:p){
			if(i*j>1000000) break;
			vis[i*j]=1;
			if(i%j==0) break;
		}
	}
}
signed main(){Rosario
	cal();
	while(cin>>n>>m,n||m){
		ll ans=1;
		for(int i=0;i<p.size()&&p[i]<=n;++i){
			ll c=0,t=n;
			while(t) c+=t/p[i],t/=p[i];
			ans=ans*power(p[i],c)%m;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
