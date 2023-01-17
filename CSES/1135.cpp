#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
 
const int z=2e5+5;
struct edge{int to,nxt;}e[z<<1];
int cnt,lca[21][z],h[z],n,q,dep[z];
void add(int u,int v){
	e[++cnt]=edge{v,h[u]};
	h[u]=cnt;
}
void dfs(int x,int p){
	for(int i=h[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(v!=p){
			lca[0][v]=x, dep[v]=dep[x]+1;
			dfs(v,x);
		}
	}
}
int LCA(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=dep[y]-dep[x],k=0;i;i>>=1,++k) if(i&1) y=lca[k][y];
	if(x==y) return x;
	for(int i=20;~i;--i) if(lca[i][x]!=lca[i][y]) x=lca[i][x],y=lca[i][y];
	return lca[0][x];
}
signed main(){valder
	cin>>n>>q;
	for(int x,y,i=1;i<n;++i) cin>>x>>y,add(x,y),add(y,x);
	dep[1]=lca[0][1]=1; dfs(1,1); 
	for(int i=1;i<=20;++i) for(int j=1;j<=n;++j) lca[i][j]=lca[i-1][lca[i-1][j]];
	for(int x,y,w;q--;){
		cin>>x>>y;
		w=LCA(x,y);
		//cout<<x<<' '<<y<<' '<<w<<'\n';
		cout<<dep[x]+dep[y]-2*dep[w]<<"\n";
	}
	return 0;
}
