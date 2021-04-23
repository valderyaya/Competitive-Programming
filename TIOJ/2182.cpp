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

const int z=1005;
int n,m,f[z][z],ans=-1e9;
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) REP1(j,1,m){
		cin>>f[i][j];
		f[i][j]=max({f[i][j],f[i-1][j]+f[i][j],f[i][j-1]+f[i][j]});
		if(j==m) ans=max(ans,f[i][j]);
		if(i==n) ans=max(ans,f[i][j]);
	}cout<<ans;
	return 0;
}
