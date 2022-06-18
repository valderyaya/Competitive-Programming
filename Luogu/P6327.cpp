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

#define int ll
const int z=2e5+5;
int laz[z<<2],n,m;
double s[z<<2],c[z<<2],sink,cosk;
#define ls rt<<1
#define rs ls|1
void up(int rt){
	s[rt]=s[ls]+s[rs];
	c[rt]=c[ls]+c[rs];
}
void upda(int rt,double x,double y){
	double nx=s[rt],ny=c[rt];
	s[rt]=nx*y+ny*x;
	c[rt]=ny*y-nx*x;
}
void down(int rt){
	if(!laz[rt]) return;
	double x=sin(laz[rt]),y=cos(laz[rt]);
	upda(ls,x,y),upda(rs,x,y);
	laz[ls]+=laz[rt],laz[rs]+=laz[rt];
	laz[rt]=0;
}
void build(int l,int r,int rt){
	if(l==r) {
		int x; cin>>x;
		s[rt]=sin(x); c[rt]=cos(x);
		return;
	}
	int mid=l+r>>1; 
	build(l,mid,rt<<1),build(mid+1,r,rt<<1|1); 
	up(rt);
}
void mfy(int l,int r,int ql,int qr,int rt,int v){
	if(ql<=l&&r<=qr){
		laz[rt]+=v;
		upda(rt,sink,cosk); return;
	}down(rt); int mid=l+r>>1;
	if(ql<=mid) mfy(l,mid,ql,qr,ls,v);
	if(qr>mid) mfy(mid+1,r,ql,qr,rs,v);
	up(rt);
}
double qry(int l,int r,int ql,int qr,int rt){
	if(ql<=l&&r<=qr) return s[rt];
	down(rt); int mid=l+r>>1; double res=0;
	if(ql<=mid) res=qry(l,mid,ql,qr,ls);
	if(qr>mid) res+=qry(mid+1,r,ql,qr,rs);
	return res;
}
 main(){Rosario
	cin>>n;
	build(1,n,1);
	cin>>m;
	for(int op,l,r,k;m;--m){
		cin>>op>>l>>r;
		if(op==1){
			cin>>k;
			sink=sin(k),cosk=cos(k);
			mfy(1,n,l,r,1,k);
		}else cout<<fixed<<setprecision(1)<<qry(1,n,l,r,1)<<"\n";
	}
	return 0;
}
