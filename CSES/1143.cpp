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

#define ls rt<<1
#define rs ls|1
int n,m,seg[800005];
void build(int l,int r,int rt){
	if(l==r) return cin>>seg[rt],void();
	int mid=l+r>>1;
	build(l,mid,ls),build(mid+1,r,rs);
	seg[rt]=max(seg[ls],seg[rs]);
}
int qry(int l,int r,int rt,int x){
	if(seg[rt]<x) return 0;
	if(l==r){
		if(seg[rt]>=x) return seg[rt]-=x,l;
		return 0;
	}int mid=l+r>>1,ret;
	if(seg[ls]>=x) ret= qry(l,mid,ls,x);
	else if(seg[rs]>=x) ret= qry(mid+1,r,rs,x);
	seg[rt]=max(seg[ls],seg[rs]);
	return ret;
}
signed main(){Aincrad
	cin>>n>>m;
	build(1,n,1);
	for(int x;m--;){
		cin>>x;
		cout<<qry(1,n,1,x)<<' ';
	}
	return 0;
}
