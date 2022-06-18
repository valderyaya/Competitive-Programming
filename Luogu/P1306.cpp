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

const ll mod=1e8;
ll n,m,a[2][2],b[2][2],c[2][2],g;
void init(){
	b[0][0]=a[1][0]=a[1][1]=0;
	a[0][0]=1,a[0][1]=2;
	b[0][1]=b[1][0]=b[1][1]=1;
}
void f(){
	c[0][0]=c[1][1]=c[1][0]=c[0][1]=0;
	REP(k,2) REP(i,2) REP(j,2) c[i][j]=(c[i][j]+b[i][k]*b[k][j])%mod;
	REP(i,2) REP(j,2) b[i][j]=c[i][j];
}
void v(){
	c[0][0]=c[1][1]=c[1][0]=c[0][1]=0;
	REP(k,2) REP(i,2) REP(j,2) c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
	REP(i,2) REP(j,2) a[i][j]=c[i][j];
}
ll cal(ll x){
	if(x<=2) return x;
	init();
	for(--x;x;x>>=1,f()) if(x&1) v();
	return a[0][0];
}
int main(){//Rosario
	cin>>n>>m;
	g=__gcd(n,m);
	if(g<=2) cout<<1;
	else cout<<cal(g-1);
	return 0;
}
