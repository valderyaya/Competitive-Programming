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
	ll a[2][2];
	matrix(){memset(a,0,sizeof(a));}
	matrix operator*(matrix &x){
		matrix rs;
		REP(k,2) REP(i,2) REP(j,2) rs.a[i][j]=(rs.a[i][j]+a[i][k]*x.a[k][j]%mod)%mod;
		return rs;
	}
}A,B;
ll n;
matrix power(matrix &x,ll N){
	matrix res;
	res.a[0][0]=res.a[1][1]=1;
	for(;N;N>>=1,x=x*x) if(N&1) res=res*x;
	return res;
}
int main(){//Rosario
	A.a[0][0]=A.a[0][1]=1;
	B.a[1][0]=B.a[0][1]=B.a[1][1]=1;
	cin>>n;
	if(n<=2) return cout<<1,0;
	matrix C=power(B,n-2);
	A=A*C;
	cout<<A.a[0][1]%mod;
	return 0;
}
