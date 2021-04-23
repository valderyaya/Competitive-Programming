//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e5+5;
int mn,ans,dp[z][2],nxt[z],n,m,l,qe[z],idx;
bitset<z> vis;
vector<pii> v[z];
void dfs(int x,int p){
    vis[x]=1;
    for(auto &i:v[x]){
        if(vis[i.F]) continue;
        dfs(i.F,x);
        if(dp[i.F][0]+i.S>dp[x][0]) dp[x][0]=dp[i.F][0]+i.S,nxt[x]=i.F;
    }
    for(auto &i:v[x]) if(i.F!=nxt[x]&&i.F!=p) dp[x][1]=max(dp[x][1],dp[i.F][0]+i.S);
}
void dfs2(int x,int d,int p){
    if(d>dp[x][0]) dp[x][1]=dp[x][0],nxt[x]=p,dp[x][0]=d;
    else if(d>dp[x][1]) dp[x][1]=d;
    mn=min(mn,dp[x][0]);
    ans=max(ans,dp[x][0]);
    for(auto &i:v[x]){
        if(i.F==p) continue;
        if(i.F!=nxt[x]) dfs2(i.F,dp[x][0]+i.S,x);
        else dfs2(i.F,dp[x][1]+i.S,x);
    }
}
int main(){Rosario
    while(cin>>n>>m>>l){
    REP(i,n) dp[i][0]=dp[i][1]=nxt[i]=0,v[i].clear();
    idx=ans=0; vis.reset();
    int x,y,z;
    while(m--) cin>>x>>y>>z,v[x].em(mkp(y,z)),v[y].em(mkp(x,z));
    REP(i,n) if(!vis[i]){mn=1e9;
        dfs(i,i); dfs2(i,0,i); qe[++idx]=mn; 
    } sort(qe+1,qe+1+idx);
    if(idx>1) ans=max(ans,qe[idx]+qe[idx-1]+l);
    if(idx>2) ans=max(ans,qe[idx-1]+qe[idx-2]+l+l);
    cout<<ans<<"\n";
    }
    return 0;
}
