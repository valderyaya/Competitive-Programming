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

const int z=1001;
int a[z][z]={},ans=0,n,m,l[z][z],r[z][z],up[z][z];
int main(){Rosario
	cin>>n>>m;
	for(int x,y;m;--m) cin>>x>>y,a[x][y]=1;
	REP1(i,1,n) REP1(j,1,n){
		l[i][j]=j;
		if(j!=1&&a[i][j]==a[i][j-1]&&a[i][j]==0) l[i][j]=l[i][j-1];
	}
	REP1(i,1,n) for(int j=n;j;--j){
		r[i][j]=j;
		if(j!=n&&a[i][j]==a[i][j+1]&&a[i][j]==0) r[i][j]=r[i][j+1];
	}
	REP1(i,1,n) REP1(j,1,n){
		up[i][j]=1;
		if(i!=1&&a[i][j]==a[i-1][j]&&a[i][j]==0){
			up[i][j]+=up[i-1][j];
			l[i][j]=max(l[i][j],l[i-1][j]);
			r[i][j]=min(r[i][j],r[i-1][j]);
		}
		int x=min(up[i][j],r[i][j]-l[i][j]+1);
		ans=max(ans,x);
	}cout<<ans<<"\n";
	return 0;
}
