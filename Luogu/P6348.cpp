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
struct edge{int to,nxt,w;}e[z*10];
int cnt,id[z*9],h[z*9],n,m,st,dis[z*9],tot;
void add(int u,int v,int w){
	e[++cnt]=edge{v,h[u],w};
	h[u]=cnt;
}
void build(int l,int r,int rt){
	if(l==r){
		add(rt,rt+4*n,0),add(rt+4*n,rt,0);
		id[l]=rt; return;
	}int mid=l+r>>1;
	add(rt,rt<<1,0),add(rt,rt<<1|1,0);
	add(rt*2+4*n,rt+4*n,0),add(rt*2+1+4*n,rt+n*4,0);
	build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
}
void ins(int l,int r,int ql,int qr,int rt,int v,int tag){
	if(ql<=l&&r<=qr){
		if(tag) add(v,rt,0);
		else add(rt+4*n,v,0);
		return;
	}int mid=l+r>>1;
	if(ql<=mid) ins(l,mid,ql,qr,rt<<1,v,tag);
	if(qr>mid) ins(mid+1,r,ql,qr,rt<<1|1,v,tag);
}
void bfs(){
	memset(dis,63,sizeof(dis));
	deque<int> dq; dis[st]=0; dq.push_front(st);
	while(!dq.empty()){
		int x=dq.front(); dq.pop_front();
		for(int i=h[x];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[x]+e[i].w){
				dis[v]=dis[x]+e[i].w;
				if(e[i].w) dq.push_back(v);
				else dq.push_front(v);
			}
		}
	}
	REP1(i,1,n) cout<<dis[id[i]]<<"\n";
}
int main(){Rosario
	cin>>n>>m>>st;
	tot=8*n;
	build(1,n,1);
	for(int a,b,c,d,x,y;m;--m){
		cin>>a>>b>>c>>d;
		x=++tot,y=++tot;
		add(y,x,1),ins(1,n,a,b,1,x,1),ins(1,n,c,d,1,y,0);
		x=++tot,y=++tot;
		add(y,x,1),ins(1,n,c,d,1,x,1),ins(1,n,a,b,1,y,0);
	}
	st=id[st]+4*n;
	bfs();
	return 0;
}
