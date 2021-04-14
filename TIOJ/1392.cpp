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
#define lb(x) (x&-x)

struct edge{int to,nxt;}e[50050];
int n,h[10005],cnt,tot,d[10005],val[10005],a[105][105];
void add(int u,int v){
	e[++cnt]=edge{v,h[u]};
	h[u]=cnt;
}
void add_edge(int u,int v){
	add(u,v);
	add(v,u);
}
bitset<10005> vis;
void init(){
	cnt=tot=0; vis.reset();
	memset(h,0,sizeof(h));
}
queue<int> q;
int spfa(){
	REP1(i,1,tot) d[i]=1e9;
	d[1]=val[1]; q.emplace(1); vis[1]=1;
	int x,res=0;
	while(!q.empty()){
		x=q.front(); q.pop(); vis[x]=0;
		for(int i=h[x];i;i=e[i].nxt){
			int v=e[i].to,tmp=1+d[x];
			if(d[v]>tmp){
				d[v]=min(d[v],max(val[v]+1,tmp));
				if(!vis[v]) q.emplace(v),vis[v]=1;
			}
		}
	}
	REP1(i,1,tot) res=max(res,d[i]);
	return res;
}
int main(){Rosario
	while(cin>>n){
		init();
		REP1(i,1,n) REP1(j,1,i) cin>>val[++tot],a[i][j]=tot;
		REP1(i,1,n-1) REP1(j,1,i){
			add_edge(a[i][j],a[i+1][j]);
			add_edge(a[i][j],a[i+1][j+1]);
		}
		cout<<spfa()<<"\n";
	}
	return 0;
}
