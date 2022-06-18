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

#define int ll
const int z=1e5+5;
int sz[z],n,m,dep[z],dfn[z],root,seg[z<<2],laz[z<<2],fa[z],son[z],id[z],top[z],cnt,tmp[z];
vector<int> v[z];
void dfs(int x){
	sz[x]=1;
	for(auto &i:v[x])
		if(!dep[i]){
			dep[i]=dep[x]+1;
			fa[i]=x; dfs(i);
			sz[x]+=sz[i];
			if(sz[i]>sz[son[x]]) son[x]=i;
		}
}
void dfs2(int x,int t){
	top[x]=t;
	dfn[x]=++cnt;
	id[cnt]=tmp[x];
	if(son[x]) dfs2(son[x],t);
	for(auto &i:v[x]) if(i!=fa[x]&&i!=son[x]) dfs2(i,i);
}
#define ls rt<<1
#define rs ls|1
void down(int rt){
	if(!laz[rt]) return;
	laz[ls]=laz[rs]=laz[rt];
	seg[ls]=seg[rs]=laz[rt];
	laz[rt]=0;
}
void build(int l,int r,int rt){
	if(l==r) return seg[rt]=id[l],void();
	int mid=l+r>>1;
	build(l,mid,ls),build(mid+1,r,rs);
	seg[rt]=min(seg[ls],seg[rs]);
}
void modify(int l,int r,int ql,int qr,int rt,int val){
	if(ql<=l&&r<=qr) return seg[rt]=laz[rt]=val,void();
	int mid=l+r>>1; down(rt);
	if(ql<=mid) modify(l,mid,ql,qr,ls,val);
	if(qr>mid) modify(mid+1,r,ql,qr,rs,val);
	seg[rt]=min(seg[ls],seg[rs]);
}
int query(int l,int r,int ql,int qr,int rt){
	if(ql<=l&&r<=qr) return seg[rt];
	int mid=l+r>>1,mn=1e18;down(rt);
	if(ql<=mid) mn=query(l,mid,ql,qr,ls);
	if(qr>mid) mn=min(mn,query(mid+1,r,ql,qr,rs));
	return mn;
}
void mod(int a,int b,int val){
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]]) swap(a,b);
		modify(1,n,dfn[top[a]],dfn[a],1,val);
		a=fa[top[a]];
	}
	if(dep[a]>dep[b]) swap(a,b);
	modify(1,n,dfn[a],dfn[b],1,val);
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(fa[top[y]]==x) return top[y];
		y=fa[top[y]];
	}
	return son[x];
}
 main(){Rosario
	cin>>n>>m;
	for(int x,y,i=1;i<n;++i) cin>>x>>y,v[x].em(y),v[y].em(x);
	REP1(i,1,n) cin>>tmp[i];
	dep[1]=1; dfs(1); dfs2(1,1);
	build(1,n,1); cin>>root;
	//REP1(i,1,n) cout<<dfn[i]<<" \n"[i==n];
	for(int opt,x,y,val;m;--m){
		cin>>opt>>x;
		if(opt==1) root=x;
		else if(opt==2){
			cin>>y>>val;
			mod(x,y,val);
		}else if(opt==3){
			if(x==root) cout<<seg[1]<<"\n";
			else{
				if(dfn[x]>=dfn[root]||dfn[x]+sz[x]-1<dfn[root]) cout<<query(1,n,dfn[x],dfn[x]+sz[x]-1,1)<<"\n";
				else{
					x=lca(x,root);
					int mn=query(1,n,1,dfn[x]-1,1);
					if(dfn[x]+sz[x]<=n) mn=min(mn,query(1,n,dfn[x]+sz[x],n,1));
					cout<<mn<<"\n";
				}
			}
		}
	}
	return 0;
}
