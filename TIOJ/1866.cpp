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

const int z=1e5+5;
struct edge{int to,nxt;}e[z<<1];
int t,n,tr[2][z*31],cnt[31*z],tot,val[z],ans[z],h[z],eg,sum;
void add(int u,int v){
	e[++eg]=edge{v,h[u]};
	h[u]=eg;
}
void ins(int x){
	int p=0;
	for(int c,i=30;i>=0;--i){
		c=((x>>i)&1);
		if(!tr[c][p]) tr[c][p]=++tot;
		p=tr[c][p];
		++cnt[p];
	}
}
void del(int x){
	for(int p=0,c,tp,i=30;i>=0;--i){
		c=((x>>i)&1);
        tp=tr[c][p];
		if(--cnt[tp]==0) tr[c][p]=0;
        p=tp;
	}	
}
int qry(int x){
	int p=0,res=0;
	for(int c,i=30;i>=0;--i){
		c=((x>>i)&1);
		if(cnt[tr[c^1][p]]) {
			res|=(1<<i);
			p=tr[c^1][p];
		}else p=tr[c][p];
	}
	return res;
}
void dfs(int x,int p,int mx){
	sum^=val[x];
	ans[x]=max(mx,qry(sum));
	ins(sum);
	for(int i=h[x];i;i=e[i].nxt)
		if(e[i].to!=p) dfs(e[i].to,x,ans[x]);
    del(sum);
    sum^=val[x];
}
signed main(){valder
	cin>>t;
    ins(0);
    int base=tot;
	while(t--){
		tot=base; eg=sum=0;
		cin>>n;
		for(int i=1;i<=n;++i) cin>>val[i],h[i]=ans[i]=0;
		for(int x,y,i=1;i<n;++i){
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		dfs(1,1,0);
		for(int i=1;i<=n;++i) cout<<ans[i]<<"\n";
	}
}
