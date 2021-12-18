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

struct edge{
	int to,nxt,w;
}e[5005];
vector<int> vec[2505];
int cnt,h[2505],n,m,tot[2505];
ll dis[2505];
bitset<2505> vis;
void add(int u,int v,int w){
	e[++cnt]=edge{v,h[u],w};
	h[u]=cnt;
}
bool dfs(int x){
	vis[x]=1;
	if(tot[x]>=n-1) return 1;
	if(x==1) return 0;
	bool ret=0;
	for(auto &i:vec[x])
		if(!vis[i]) ret|=dfs(i);
	return ret;
}
bool spfa(){
	REP1(i,2,n) dis[i]=-1e18;
	queue<int> q;
	q.emplace(1); vis[1]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop(); vis[x]=0;
		for(int v,i=h[x];i;i=e[i].nxt){
			v=e[i].to;
			if(dis[v]<dis[x]+e[i].w){
				if(++tot[v]>=n) {
					vis.reset();
					return dfs(n);
				}
				dis[v]=dis[x]+e[i].w;
				if(!vis[v]) vis[v]=1,q.emplace(v);
			}
		}
	}
	return 0;
}
signed main(){Aincrad
	cin>>n>>m;
	for(int x,y,z;m;--m) cin>>x>>y>>z,add(x,y,z),vec[y].em(x);
	cout<<(spfa()?-1:dis[n])<<"\n";
	//REP1(i,1,n) cout<<dis[i]<<" \n"[i==n];
	return 0;
}
