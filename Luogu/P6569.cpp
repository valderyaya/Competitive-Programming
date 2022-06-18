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

ll n,m,q,val[105],f[105];
struct mxt{
	bool c[105][105];
	mxt(){memset(c,0,sizeof(c));}
	mxt operator*(mxt &x)const{
		mxt res;
		REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) res.c[i][j]^=c[i][k]&x.c[k][j];
		return res;
	}
}p[33];
void mul(ll x){
	ll tmp[105]={};
	REP1(i,1,n) REP1(j,1,n) if(p[x].c[i][j]) tmp[i]^=f[j];
	REP1(i,1,n) f[i]=tmp[i];
}
int main(){Rosario
	cin>>n>>m>>q;
	REP1(i,1,n) cin>>val[i];
	for(ll x,y;m;m--) cin>>x>>y,p[0].c[x][y]=p[0].c[y][x]=1;
	REP1(i,1,31) p[i]=p[i-1]*p[i-1];
	for(ll x;q;q--){ cin>>x;
		REP1(i,1,n) f[i]=val[i];
		for(ll i=0;i<=31;++i) if(x>>i&1) mul(i);
		cout<<f[1]<<"\n";
	}
	return 0;
}
