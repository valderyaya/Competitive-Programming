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
char a[z][z];
int n,m,mx=0,r[z][z],l[z][z],up[z][z];
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) REP1(j,1,m) {
		cin>>a[i][j],up[i][j]=1;
		if(a[i][j]=='F') l[i][j]=r[i][j]=j;
		else l[i][j]=1e4,r[i][j]=-1e4;
	}
	REP1(i,1,n) REP1(j,2,m) if(a[i][j]==a[i][j-1]&&a[i][j]=='F') l[i][j]=min(l[i][j],l[i][j-1]);
	REP1(i,1,n) for(int j=m-1;j;--j) if(a[i][j]==a[i][j+1]&&a[i][j]=='F') r[i][j]=max(r[i][j],r[i][j+1]);
	REP1(i,1,n) REP1(j,1,m){
		if(i!=1&&a[i][j]==a[i-1][j]&&a[i][j]=='F'){
			up[i][j]+=up[i-1][j];
			l[i][j]=max(l[i][j],l[i-1][j]);
			r[i][j]=min(r[i][j],r[i-1][j]);
		}
		mx=max(mx,up[i][j]*(r[i][j]-l[i][j]+1));
	}
	cout<<mx*3<<'\n';
	return 0;
}
