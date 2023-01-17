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
 
const int z=2e5+5;
struct edge{int to,nxt;}e[z<<1];
int d[z],n,h[z],cnt,mn=1e9,ans;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x,int p){
    d[x]=1;
    int mx=0;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v!=p){
            dfs(v,x);
            d[x]+=d[v];
            mx=max(mx,d[v]);
        }
    }
    mx=max(mx,n-d[x]);
    if(mx<mn) mn=mx,ans=x;
}
signed main(){valder
    cin>>n;
    for(int i=1,x,y;i<n;++i) cin>>x>>y,add(x,y),add(y,x);
    dfs(1,1);
    cout<<ans<<"\n";
}
