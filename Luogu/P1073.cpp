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

const int z=1e5+5;
vector<int> v[z],v2[z];
int low[z],dfn[z],tot,n,m,w[z],mx[z],mn[z],col[z],cl,ans,in[z],f[z];
bool vis[z];
stack<int> st;
void dfs(int x){
	low[x]=dfn[x]=++tot;
	st.emplace(x); vis[x]=1;
	for(auto &i:v[x]){
		if(!dfn[i]){
			dfs(i);
			low[x]=min(low[x],low[i]);
		}else if(vis[i]&&dfn[i]<dfn[x]) low[x]=min(low[x],dfn[i]);
	}
	if(low[x]==dfn[x]){
		++cl;
		for(int u=-1;u!=x;st.pop()){
			u=st.top(); vis[u]=0; col[u]=cl;
			mx[cl]=max(mx[cl],w[u]);
			mn[cl]=min(mn[cl],w[u]);
		}
	}
}
void build(){
	REP1(i,1,n) for(auto &j:v[i]) if(col[i]!=col[j]) v2[col[i]].em(col[j]),in[col[j]]++;
}
void topo(){
	queue<int> q;
	memset(vis,0,sizeof(vis));
	REP1(i,1,cl) if(in[i]==0) q.emplace(i);
	//f[col[1]]=max(f[col[1]],mx[col[1]]-mn[col[1]]);
	vis[col[1]]=1;
	while(!q.empty()){
		int x=q.front(); q.pop();
		f[x]=max(f[x],mx[x]-mn[x]);
		for(auto &j:v2[x]){
			if(vis[x]){
				vis[j]=1;
				mn[j]=min(mn[j],mn[x]);
				f[j]=max({f[x],f[j],mx[j]-mn[j]});
			}
			if(--in[j]==0) q.emplace(j);
		}
	}
}
signed main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) cin>>w[i],mn[i]=120;
	for(int x,y,p;m;--m){
		cin>>x>>y>>p;
		v[x].em(y);
		if(p==2) v[y].em(x);
	}
	REP1(i,1,n) if(!dfn[i]) dfs(i);
	build();
	topo();
	cout<<f[col[n]]<<"\n";
	return 0;
}
