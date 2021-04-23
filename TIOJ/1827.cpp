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

const int z=1e5+5;
int n,m,rt[z],cnt,lc[z*70],rc[z*70],sum[z*70];
void build(int l,int r,int &o){
	if(!o) o=++cnt;
	sum[o]=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid,lc[o]),build(mid+1,r,rc[o]);
}
void mdf(int prv,int &o,int l,int r,int x){
	o=++cnt;
	lc[o]=lc[prv], rc[o]=rc[prv], sum[o]=sum[prv]+1;
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) mdf(lc[prv],lc[o],l,mid,x);
	else mdf(rc[prv],rc[o],mid+1,r,x);
}
int qry(int l,int r,int o,int ql,int qr){
	if(ql<=l&&r<=qr) return sum[o];
	int mid=l+r>>1,s=0;
	if(ql<=mid) s=qry(l,mid,lc[o],ql,qr);
	if(qr>mid) s+=qry(mid+1,r,rc[o],ql,qr);
	return s;
}
int get_(int l,int r,int k){
	int res=qry(1,n,rt[r],1,k)-qry(1,n,rt[l-1],1,k);
	return res;
}
signed main(){Rosario
	cin>>n>>m;
	build(1,n,rt[0]);
	for(int x,i=1;i<=n;++i) cin>>x,mdf(rt[i-1],rt[i],1,n,x);
	for(int mid,l,r,p,k,o;m;--m){
		cin>>p>>k; ++p;
		l=1,r=n;
		while(l<r){
			mid=l+r>>1;
			if(get_(max(1,p-mid),min(n,p+mid),mid)<k) l=mid+1;
			else r=mid;
		}
		cout<<l<<"\n";
	}
	return 0;
}
