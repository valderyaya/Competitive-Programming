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

#define int ll
int t,n,l,c,f[100005];
struct qwq{
	int l,r,val;
	bool operator<(const qwq &x)const{return r<x.r;}
}a[100005];
int bin(int x){
	int l=1,r=n,m,res=1;
	while(l<r){
		m=l+r>>1;
		if(a[m].r<=x) l=m+1;
		else res=m,r=m;
	}return res;
}
 main(){Rosario
	cin>>t;
	while(t--){
		cin>>n>>l>>c;
		for(int x,t,i=1;i<=n;++i){
			cin>>x>>t;
			a[i].l=x,a[i].r=x+t,a[i].val=c-(x+t);
		}
		memset(f,0,sizeof(f));
		sort(a+1,a+1+n);
		REP1(i,1,n){
			f[i]=max(f[i-1],f[bin(a[i].l)-1]+a[i].val);
		}cout<<f[n]<<"\n";
	}
	return 0;
}
