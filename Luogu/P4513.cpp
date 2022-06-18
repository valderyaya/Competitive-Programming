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

const int z=5e5+5;
struct qwq{
	int sum,lmx,rmx,mx;
	qwq(){sum=lmx=rmx=mx=0;}
}seg[z<<2];
int n,m;
#define ls rt<<1
#define rs ls|1
void up(int rt){
	seg[rt].mx=max({seg[ls].mx,seg[rs].mx,seg[rs].lmx+seg[ls].rmx});
	seg[rt].lmx=max(seg[ls].lmx,seg[ls].sum+seg[rs].lmx);
	seg[rt].rmx=max(seg[rs].rmx,seg[rs].sum+seg[ls].rmx);
	seg[rt].sum=seg[ls].sum+seg[rs].sum;
}
void build(int l,int r,int rt){
	if(l==r) return cin>>seg[rt].mx,seg[rt].lmx=seg[rt].rmx=seg[rt].sum=seg[rt].mx,void();
	int mid=l+r>>1;
	build(l,mid,ls); build(mid+1,r,rs);
	up(rt);
}
void mdf(int l,int r,int x,int rt,int v){
	if(l==r) return seg[rt].lmx=seg[rt].rmx=seg[rt].sum=seg[rt].mx=v,void();
	int mid=l+r>>1;
	if(x<=mid) mdf(l,mid,x,ls,v);
	else mdf(mid+1,r,x,rs,v);
	up(rt);
}
qwq qry(int l,int r,int ql,int qr,int rt){
	if(ql<=l&&r<=qr) return seg[rt];
	int mid=l+r>>1;
	if(qr<=mid) return qry(l,mid,ql,qr,ls);
	else if(ql>mid) return qry(mid+1,r,ql,qr,rs);
	qwq res,L=qry(l,mid,ql,qr,ls),R=qry(mid+1,r,ql,qr,rs);
	res.mx=max({L.rmx+R.lmx,L.mx,R.mx});
	res.lmx=max(L.lmx,L.sum+R.lmx);
	res.rmx=max(R.rmx,R.sum+L.rmx);
	res.sum=L.sum+R.sum;
	return res;
}
signed main(){Rosario
	cin>>n>>m;
	build(1,n,1);
	for(int op,x,y;m;--m){
		cin>>op>>x>>y;
		if(op==1){
			if(x>y) swap(x,y);
			cout<<qry(1,n,x,y,1).mx<<"\n";
		}else mdf(1,n,x,1,y);
	}
	return 0;
}
