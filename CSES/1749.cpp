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
 
int n,seg[800005],a[200005];
#define ls rt<<1
#define rs ls|1
void build(int l,int r,int rt){
	if(l==r) return seg[rt]=1,void();
	int mid=l+r>>1;
	build(l,mid,ls),build(mid+1,r,rs);
	seg[rt]=seg[ls]+seg[rs];
}
int qry(int l,int r,int rt,int x){
	if(l==r) return --seg[rt],a[l];
	int mid=l+r>>1,ret;
	if(seg[ls]>=x) ret= qry(l,mid,ls,x);
	else ret= qry(mid+1,r,rs,x-seg[ls]);
	seg[rt]=seg[ls]+seg[rs];
	return ret;
}
signed main(){Aincrad
	cin>>n;
	REP1(i,1,n) cin>>a[i];
	build(1,n,1);
	for(int i=1,x;i<=n;++i) cin>>x,cout<<qry(1,n,1,x)<<" \n"[i==n];
	return 0;
}
