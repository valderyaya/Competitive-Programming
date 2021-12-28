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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

const int z=2e5+5;
int n,m,cnt[z],lca[20][z],dep[z];
vector<int> v[z];
void dfs(int x,int p){
	dep[x]=dep[p]+1;
	for(auto &i:v[x]){
		if(i==p) continue;
		lca[0][i]=x;
		dfs(i,x);
	}
}
void dfs2(int x){
	for(auto &i:v[x])
		if(i!=lca[0][x]){
			dfs2(i);
			cnt[x]+=cnt[i];
		}
}
int Lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=dep[y]-dep[x],k=0;i;i>>=1,++k)
		if(i&1) y=lca[k][y];
	if(x==y) return x;
	for(int i=19;~i;--i) if(lca[i][x]^lca[i][y]) x=lca[i][x],y=lca[i][y];
	return lca[0][x];
}
signed main(){Aincrad
	cin>>n>>m;
	for(int x,y,i=1;i<n;++i) cin>>x>>y,v[x].em(y),v[y].em(x);
	dfs(1,1);
	for(int i=1;i<20;++i) for(int j=1;j<=n;++j) lca[i][j]=lca[i-1][lca[i-1][j]];
	for(int l,r,x;m--;){
		cin>>l>>r;
		++cnt[l],++cnt[r],--cnt[x=Lca(l,r)];
		--cnt[lca[0][x]];
	}
	dfs2(1);
	REP1(i,1,n) cout<<cnt[i]<<" \n"[i==n];
	return 0;
}
