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
	ll a[3][3],n,m;
	matrix(){memset(a,0,sizeof(a));}
	ll* operator[](ll x){return a[x];}
	matrix operator*(matrix &x){
		matrix rs;
		rs.n=n,rs.m=x.m;
		REP(k,m) REP(i,rs.n) REP(j,rs.m) rs.a[i][j]=(rs.a[i][j]+a[i][k]*x.a[k][j])%mod;
		return rs;
	}
}A,B[32];
ll n,m;
void power(matrix x,ll N){
	matrix res;
	res.a[0][0]=res.a[1][1]=res.a[2][2]=1;
	res.n=res.m=3;
	for(ll i=0;i<32;++i)
		if(N>>i&1) res=res*B[i];
	x=x*res;
	cout<<x[0][0]<<'\n';
}
int main(){Rosario
	A.a[0][0]=A.a[0][1]=A.a[0][2]=1;
	A.n=1,A.m=3;
	B[0].a[1][0]=B[0].a[2][1]=B[0].a[0][2]=B[0].a[2][2]=1;
	B[0].n=B[0].m=3;
	for(int i=1;i<32;++i) B[i]=B[i-1]*B[i-1];
	cin>>n;
	while(n--){
		cin>>m;
		if(m<=3){
			cout<<"1\n";
			continue;
		}
		power(A,m-1);
	}
	return 0;
}
