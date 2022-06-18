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

#define int ll
const int z=50005;
int dis[z],n,m,city[z],pa[z],Lon,mul[z];
vector<pii> v[z];
vector<int> son;
bool cov[z];
bitset<z> used;
void dfs(int x,int p){
	pa[x]=(p==1?x:pa[p]);
	Lon=max(Lon,dis[x]);
	for(auto &i:v[x]){
		if(i.F==p) continue;
		dis[i.F]=dis[x]+i.S;
		dfs(i.F,x);
	}
}
int dfs2(int x,int p,int mid){
	if(cov[x]) return 0;
	int res=1e14,leaf=1;
	cov[x]=1;
	for(auto &i:v[x]){
		if(i.F==p) continue;
		leaf=0;
		res=min(res,i.S+dfs2(i.F,x,mid));
		cov[x]&=cov[i.F];
	}
	if(leaf) return cov[x]=0,res;
	cov[x]|= res<=mid;
	return res;
}
bool cmp(int x,int y){return dis[x]>dis[y];}
bool check(int mid){
	fill(cov,cov+n+1,0);
	used.reset();
	fill(mul,mul+n+1,-1);
	int i,u,p;
	for(i=0;i<m&&dis[city[i]]>mid;++i) cov[city[i]]=1;
	dfs2(1,0,mid);
	for(p=i;i<m;++i)
		if(!~mul[pa[city[i]]]) mul[pa[city[i]]]=i;
	u=m;
	for(i=0;i<son.size();++i){
		int c=son[i];
		if(cov[c]) continue;
		if(mul[c]==-1||used[mul[c]]){
			for(--u;u>=p&&(dis[city[u]]+dis[c]>mid||used[u]);--u);
			if(u<p) break;
			used[u]=1;
		}else used[mul[c]]=1;
	}
	return u>=p;
}
signed main(){valder
	cin>>n;
	for(int i=1,x,y,c;i<n;++i){
		cin>>x>>y>>c;
		v[x].em(y,c);
		v[y].em(x,c);
	}
	cin>>m;
	REP(i,m) cin>>city[i];
	dfs(1,0);
	for(auto &i:v[1]) son.em(i.F);
	sort(ALL(son),cmp);
	sort(city,city+m,cmp);
	int l=0,r=Lon+(son.empty()?0:dis[son[0]]),mid;
	while(l<r){
		mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
	return 0;
}
