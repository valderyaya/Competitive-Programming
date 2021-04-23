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

const ll mod=1e9+7;
struct matrix{
	ll a[101][101],m,n;
	matrix(){memset(a,0,sizeof(a));}
	matrix operator*(const matrix &x)const{
		matrix res;
		res.n=n,res.m=x.m;
		REP(k,m) REP(i,res.n) REP(j,res.m) res.a[i][j]=(res.a[i][j]+a[i][k]*x.a[k][j]%mod)%mod;
		return res;
	}
}p[32],base;

matrix power(ll n){
	matrix res=base;
	for(ll i=0;i<=30;++i)
		if(n>>i&1) res=res*p[i];
	return res;
}
void rd(ll &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
}
ll n,m;
int main(){//Rosario
	rd(n);
	p[0].n=p[0].m=n;
	base.n=1,base.m=n;
	REP(i,n) cin>>base.a[0][i];
	rd(m);
	REP(i,n) REP(j,n) p[0].a[i][j]=i==j;
	for(ll x,y,c;m;--m){
		rd(x),rd(y),rd(c);
		if(x==y) continue;
		p[0].a[x][y]=c;
	}
	//REP(i,n) REP(j,n) cout<<p[0].a[i][j]<<" \n"[j==n-1];
	for(int i=1;i<=30;++i) p[i]=p[i-1]*p[i-1];
	rd(m);
	ll day;
	while(m--){
		rd(day);
		matrix ans=power(day);
		REP(i,n) printf("%d ",ans.a[0][i]);//cout<<ans.a[0][i]<<" \n"[i==n-1];
		puts("");
	}
	return 0;
}
