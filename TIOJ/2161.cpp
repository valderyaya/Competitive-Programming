//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long

const int z=2e5+5;
pii par[z];
int n,m,d[z],pa[z];
vector<pii> v[z];
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void mer(int x,int y){
    x=fin(x),y=fin(y);
    pa[x]=y;
}
void dfs(int x, int p, int dep){
    d[x]=dep;
    for(auto &i:v[x]){
        if(i.F==p) continue;
        par[i.F]={x,i.S};
        dfs(i.F,x,dep+1);    
    }
}
signed main(){StarBurstStream
    cin>>n>>m;
    for(int x,y,w,i=1;i<n;++i){
        cin>>x>>y>>w;
        v[x].em(y,w);
        v[y].em(x,w);
    }
    dfs(1,1,0);
    REP1(i,1,n) pa[i]=i;
    for(int ans,x,y;m--;){
        cin>>x>>y;
        ans=0;
        while(x!=y){
            if(d[x]<d[y]) swap(x,y);
            if(fin(x)==x){
                ans+=par[x].S;
                mer(x,par[x].F);
            }
            x=fin(x);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
