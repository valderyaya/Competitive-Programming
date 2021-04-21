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

const int z=10005,zz=100005;
struct edge{int to,nxt;}e[zz<<1],e2[zz<<1];
int h[z],cnt,cnt2,t,n,m,h2[z],sum[z],dfn[z],tot,low[z],col[z],cl,in[z],w[z];
stack<int> st;
bitset<z> ins;
void add(int u,int v){
	e[++cnt]=edge{v,h[u]};
	h[u]=cnt;
}
void add2(int u,int v){
	e2[++cnt2]=edge{v,h2[u]};
	h2[u]=cnt2;
}
void init(){
	cnt=tot=cl=cnt2=0;
	ins.reset();
	while(!st.empty()) st.pop();
	memset(h,0,sizeof(h));
	memset(h2,0,sizeof(h2));
	memset(in,0,sizeof(in));
	memset(sum,0,sizeof(sum));
	memset(w,0,sizeof(w));
	memset(col,0,sizeof(col));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
}
queue<int> q;
void dfs(int x){
	dfn[x]=low[x]=++tot;
	st.emplace(x); ins[x]=1;
	for(int i=h[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(!dfn[v]) dfs(v),low[x]=min(low[x],low[v]);
		else if(ins[v]) low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]){
		++cl;
		for(int u=0;u!=x;st.pop()){
			u=st.top(); ins[u]=0;
			col[u]=cl; w[cl]++;
		}
	}
}
void build(){
	REP1(i,1,n) if(!dfn[i]) dfs(i);
	REP1(i,1,n)
		for(int j=h[i];j;j=e[j].nxt)
			if(col[i]!=col[e[j].to]) add2(col[i],col[e[j].to]),++in[col[e[j].to]];
}
int topo(){
	int res=0;
	while(!q.empty()) q.pop();
	REP1(i,1,cl) if(in[i]==0) sum[i]=w[i],q.emplace(i);
	while(!q.empty()){
		int x=q.front(); q.pop();
		res=max(res,sum[x]);
		for(int i=h2[x];i;i=e2[i].nxt){
			int v=e2[i].to;
			sum[v]=max(sum[v],sum[x]+w[v]);
			if(--in[v]==0) q.emplace(v);
		}
	}
	return res;
}
int main(){Rosario
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(n==0){
			cout<<"0\n";
			continue;
		}else if(m==0){
			cout<<"1\n";
			continue;
		}
		init();
		for(int x,y;m;--m) cin>>x>>y,add(x,y);
		build();
		cout<<topo()<<"\n";
	}
	return 0;
}
