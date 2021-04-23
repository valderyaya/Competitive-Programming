#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

#define int ll
const int z=4e4+5,mod=1000000007;
struct qq{
	int l,r,sl,id;
	bool operator<(const qq &x)const{return sl==x.sl?r<x.r:l<x.l;}
}q[400005];
inline void rd(ll &x){
	x=0;char c=getchar_unlocked();
	while(c<'0'||c>'9') c=getchar_unlocked();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar_unlocked();
}
int n,m,a[z],c[z],sum=0,cnt[z],ans[400005];
inline void rev(){
	sum%=mod;
	if(sum<0) sum+=mod;
}
inline void add(int x){
	sum-=cnt[x]*c[x]%mod*cnt[x];
	++cnt[x];
	sum+=cnt[x]*c[x]%mod*cnt[x];
	rev();
}
inline void sub(int x){
	sum-=cnt[x]*c[x]%mod*cnt[x];
	--cnt[x];
	sum+=cnt[x]*c[x]%mod*cnt[x];
	rev();
}
inline void solve(){
	for(int i=0,l=0,r=0;i<m;++i){
		while(r<q[i].r) add(a[r++]);
		while(r>q[i].r) sub(a[--r]);
		while(l<q[i].l) sub(a[l++]);
		while(l>q[i].l) add(a[--l]);
		ans[q[i].id]=sum;
	}
}
int tmp[32];
void write(int x){
	if(x==0) return puts("0"),void();
	int idx=0;
	for(;x;x/=10) tmp[++idx]=x%10;
	for(;idx;--idx) putchar_unlocked(tmp[idx]+'0');
	puts("");
}
main(){//Rosario
	rd(n),rd(m);
	int sq=sqrt(n);
	REP(i,n) rd(a[i]),c[i]=a[i];
	sort(c,c+n);
	REP(i,n) a[i]=lower_bound(c,c+n,a[i])-c;
	REP(i,m) rd(q[i].l),rd(q[i].r),q[i].id=i,q[i].sl=q[i].l/sq;
	sort(q,q+m);  solve();
	REP(i,m) write(ans[i]);
	return 0;
}
