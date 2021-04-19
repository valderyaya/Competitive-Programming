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

const int z=1e6+5;
struct edge{int to,nxt;}e[z<<1];
int tt,n,m,st,ed,fa[z],cnt[z],h[z];
void add(int u,int v){
	e[++tt]=edge{v,h[u]};
	h[u]=tt;
}
bitset<z> vis;
queue<pii> q;
void bfs(){
	q.emplace(ed,0); vis[ed]=1;
	while(!q.empty()){
		int x=q.front().F,y=q.front().S; q.pop();
		for(int i=h[x];i;i=e[i].nxt){
			int v=e[i].to;
			if(!vis[v]){
				cnt[v]=y;
				fa[v]=x;
				q.emplace(v,y+1);
				vis[v]=1;
			}else if(cnt[v]>y||(cnt[v]==y&&fa[v]>x)) cnt[v]=y,fa[v]=x;
		}
	}
	cout<<cnt[st]<<"\n";
	for(int i=st;i!=ed;i=fa[i]) cout<<i<<'-';
	cout<<ed;
}
int main(){Rosario
	cin>>n>>m>>st>>ed;
	for(int x,y;m;--m) cin>>x>>y,add(x,y),add(y,x);
	bfs();
	return 0;
}
