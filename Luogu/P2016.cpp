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

const int z=1505;
struct edge{int to,nxt;}e[z<<1];
int dp[2][z],cnt=0,n,h[z];
void add(int u,int v){
	e[++cnt]=edge{v,h[u]};
	h[u]=cnt;
}
void dfs(int x,int p){
	dp[1][x]=1;
	for(int i=h[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==p) continue;
		dfs(v,x);
		dp[0][x]+=dp[1][v];
		dp[1][x]+=min(dp[1][v],dp[0][v]);
	}
}
int main(){Rosario
	cin>>n;
	for(int x,k,i=0,y;i<n;++i){
		cin>>x>>k;
		while(k--) cin>>y,add(x,y),add(y,x);
	}dfs(1,1);
	cout<<min(dp[1][1],dp[0][1])<<"\n";
	return 0;
}
