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

const int z=2001;
int n,m,a[z][z],le[z][z],re[z][z],up[z][z],ans1=0,ans2=0;
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) REP1(j,1,m) cin>>a[i][j],le[i][j]=re[i][j]=j;
	REP1(i,1,n) REP1(j,2,m) if(a[i][j-1]!=a[i][j]) le[i][j]=le[i][j-1];
	REP1(i,1,n) for(int j=m-1;j;--j) if(a[i][j+1]!=a[i][j]) re[i][j]=re[i][j+1];
	REP1(i,1,n) REP1(j,1,m){
		up[i][j]=1;
		if(i!=1&&a[i][j]!=a[i-1][j]){
			up[i][j]+=up[i-1][j];
			le[i][j]=max(le[i][j],le[i-1][j]);
			re[i][j]=min(re[i][j],re[i-1][j]);
		}
		int mn=min(re[i][j]-le[i][j]+1,up[i][j]);
		ans1=max(ans1,mn*mn);
		ans2=max(ans2,(up[i][j])*(re[i][j]-le[i][j]+1));
	}cout<<ans1<<'\n'<<ans2<<"\n";
	return 0;
}
