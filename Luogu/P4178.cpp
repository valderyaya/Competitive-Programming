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
const int z=4e4+5,inf=1e9;
int n,ls[z<<5],cnt,node,rs[z<<5],sum[z<<5],sz[z],mx[z],rt,k,ans,root;
vector<pii> v[z];
bool vis[z];
void mdf(int &o,int l,int r,int x,int val){
	if(!o) o=++cnt;
	if(l==r){
		sum[o]+=val;
		if(!sum[o]) o=0;
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid) mdf(ls[o],l,mid,x,val);
	else mdf(rs[o],mid+1,r,x,val);
	sum[o]=sum[ls[o]]+sum[rs[o]];
	if(!sum[o]) o=0;
}
int qry(int l,int r,int ql,int qr,int o){
	if(!o||qr<l||ql>r) return 0;
	if(ql<=l&&r<=qr) return sum[o];
	int mid=l+r>>1;
	return qry(l,mid,ql,qr,ls[o])+qry(mid+1,r,ql,qr,rs[o]);
}
void calrt(int x,int fa){
	sz[x]=1; mx[x]=0;
	for(auto &i:v[x]){
		if(i.F!=fa && !vis[i.F]) {
			calrt(i.F,x);
			sz[x]+=sz[i.F];
			mx[x]=max(mx[x],sz[i.F]);
		}
	}
	mx[x]=max(mx[x],node-sz[x]);
	if(mx[rt]>mx[x]) rt=x;
}
int idx,dd[z],dis[z];
queue<int> tag;
void clear(){
	while(!tag.empty()) mdf(root,0,40000000,tag.front(),-1),tag.pop();
	cnt=0;
}
void caldis(int x,int fa){
	dd[++idx]=dis[x];
	for(auto &i:v[x]) 
		if(i.F!=fa&&!vis[i.F]) 
			dis[i.F]=dis[x]+i.S,caldis(i.F,x);
}
void dfs(int x,int fa){
	vis[x]=1; tag.emplace(0);
	mdf(root,0,40000000,0,1);
	for(auto &i:v[x])
		if(i.F!=fa &&!vis[i.F]){
			dis[i.F]=i.S;
			caldis(i.F,x);
			REP1(j,1,idx) 
				if(k>=dd[j]) 
					ans+=qry(0,40000000,0,k-dd[j],root);
			REP1(j,1,idx) mdf(root,0,40000000,dd[j],1),tag.emplace(dd[j]);
			idx=0;
		}
	clear();
	for(auto &i:v[x])
		if(i.F!=fa&&!vis[i.F]){
			node=sz[i.F];
			mx[rt=0]=inf;
			calrt(i.F,-1);
			calrt(rt,-1);
			dfs(rt,-1);
		}
}
signed main(){Rosario
	cin>>n;
	for(int x,y,w,i=1;i<n;++i) cin>>x>>y>>w,v[x].em(y,w),v[y].em(x,w);
	cin>>k; node=n;
	mx[rt=0]=inf;
	calrt(1,-1); calrt(rt,-1);
	dfs(rt,-1);
	cout<<ans<<"\n";
	return 0;
}
