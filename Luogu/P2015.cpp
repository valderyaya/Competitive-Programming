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

int n,m,dp[105][105]={},sz[105]={};
vector<pii> v[101];
void dfs(int x,int pa){
	for(auto &i:v[x]){
		if(i.F==pa) continue;
		dfs(i.F,x);
		sz[x]+=sz[i.F]+1;
		for(int j=min(sz[x],m);j;--j)
			for(int k=min(sz[i.F],j-1);k>=0;--k)
				dp[x][j]=max(dp[x][j],dp[x][j-k-1]+dp[i.F][k]+i.S);
	}
}
int main(){Rosario
	cin>>n>>m;
	int x,y,k;
	REP(i,n-1) cin>>x>>y>>k,v[x].em(mkp(y,k)),v[y].em(mkp(x,k));
	dfs(1,1);
	cout<<dp[1][m]<<"\n";
	return 0;
}
