//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=100005;
int n,dep[z],xo[20][z],lca[20][z],cnt=0,h[z],m;
struct edge{int to,nxt,w;}e[z<<1];
void add(int u,int v,int w){
	e[++cnt]=edge{v,h[u],w};
	h[u]=cnt;
}
void dfs(int x){
	for(int i=h[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(dep[v]) continue;
		dep[v]=dep[x]+1; lca[0][v]=x, xo[0][v]=e[i].w;
		dfs(v);
	}
}
void build(){
	for(int j=1;j<20;++j) 
		for(int i=1;i<=n;++i) 
			lca[j][i]=lca[j-1][lca[j-1][i]],xo[j][i]=xo[j-1][i]^xo[j-1][lca[j-1][i]];
}
int Lca(int a,int b){
	if(dep[a]<dep[b]) swap(a,b);
	int res=0;
	for(int i=dep[a]-dep[b],k=0;i;i>>=1,++k) if(i&1) res^=xo[k][a],a=lca[k][a];
	if(a==b) return res;
	for(int i=19;~i;--i) if(lca[i][a]!=lca[i][b]) res^=xo[i][a]^xo[i][b],a=lca[i][a],b=lca[i][b];
	return res^xo[0][a]^xo[0][b];
}
int main(){Rosario
	cin>>n;
	int x,y,c;
	REP(i,n-1) cin>>x>>y>>c,add(x,y,c),add(y,x,c);
	dep[1]=1; dfs(1); build();
	cin>>m;
	while(m--){
		cin>>x>>y;
		cout<<Lca(x,y)<<"\n";
	}
	return 0;
}
