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


void rd(ll &x){
	x=0;char c=getchar_unlocked();
	while(c<'0'||c>'9') c=getchar_unlocked();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar_unlocked();
}
ll ans,n,p,k,K,a[5000005],prv[5000005],suf[5000005];
ll inv(ll x){
	if(x==1) return 1;
	return (p-p/x)*inv(p%x)%p;
}
int main(){//Rosario
	rd(n),rd(p),rd(k);
	prv[0]=suf[n+1]=1; K=k;
	REP1(i,1,n) rd(a[i]),prv[i]=prv[i-1]*a[i]%p;
	for(register int i=n;i;--i) suf[i]=suf[i+1]*a[i]%p;
	REP1(i,1,n){
		ans=(ans+K*prv[i-1]%p*suf[i+1])%p;
		K=K*k%p;
	}
	printf("%lld\n",ans*inv(prv[n])%p);
	return 0;
}
