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

const ll mod=1000000009;
ll n,m,s,t,k;
struct matrix{
	ll a[101][101];
	matrix(){memset(a,0,sizeof(a));}
	matrix operator*(const matrix &x)const{
		matrix res;
		REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) res.a[i][j]=(res.a[i][j]+a[i][k]*x.a[k][j]%mod)%mod;
		return res;
	}
}p;
matrix power(){
	matrix res;
	REP1(i,1,n) res.a[i][i]=1;
	for(;k;k>>=1,p=p*p) if(k&1) res=res*p;
	return res;
}
int main(){Rosario
	cin>>n>>m>>s>>t>>k;
	for(ll x,y;m;--m){
		cin>>x>>y;
		p.a[x][y]++,p.a[y][x]++;
	}
	matrix ans=power();
	cout<<ans.a[s][t]<<"\n";
	return 0;
}
