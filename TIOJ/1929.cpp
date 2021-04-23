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

const int z=1000001;
int n,m,low[z],cl=0,dfn[z],bel[z],now=0,ans[z]={},in[z];
stack<int> st;
bitset<z> vis;
vector<int> v[z],v2[z];
void dfs(int x){
	low[x]=dfn[x]=++now; st.emplace(x); vis[x]=1;
	for(auto &i:v[x])
		if(!dfn[i]) dfs(i),low[x]=min(low[x],low[i]);
		else if(vis[i]) low[x]=min(low[x],dfn[i]);
	if(low[x]==dfn[x]){++cl;
		for(int u=-1;u!=x;st.pop()) u=st.top(),vis[u]=0,bel[u]=cl;
	}
}
int solve(){
	int cc=0;
	queue<int> q;
	REP1(i,1,cl) if(!in[i]) q.emplace(i);
	while(!q.empty()){
		int x=q.front(); q.pop();
		ans[x]=++cc;
		for(auto &i:v2[x]) if(--in[i]==0) q.emplace(i);
	}
	return cc;
}
int main(){Rosario
	cin>>n>>m;
	int x,y;
	while(m--) cin>>x>>y,v[x].em(y);
	REP1(i,1,n) if(!dfn[i]) dfs(i);
	REP1(i,1,n) for(auto &j:v[i]) if(bel[i]!=bel[j]) v2[bel[i]].em(bel[j]),in[bel[j]]++;
	cout<<solve()<<"\n";
	REP1(i,1,n) cout<<ans[bel[i]]<<' ';
	return 0;
}
