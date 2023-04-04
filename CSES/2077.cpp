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
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

const int maxn=100005;
int now=0,dfn[maxn],tot,m,low[maxn],n;
vector<int> v[maxn],ans;
void dfs(int x,int rt){
    low[x]=dfn[x]=++tot;
    int cnt=0, ck=0;
    for(auto &i:v[x]){
        if(!dfn[i]){
            dfs(i,x);
            ++cnt;
            low[x]=min(low[x],low[i]);
            if(dfn[x]<=low[i]&&x!=rt) ck=1;
        }else if(dfn[i]<dfn[x]) low[x]=min(low[x],dfn[i]);
    }
    if((x==rt&&cnt>1)||ck) ans.em(x);
}
signed main(){StarBurstStream
    cin>>n>>m;
    for(int x,y;m--;){
        cin>>x>>y;
        v[x].em(y);
        v[y].em(x);
    }
    for(int i=1;i<=n;++i) if(!dfn[i]) dfs(i,i);
    cout<<ans.size()<<"\n";
    for(auto &i:ans) cout<<i<<' ';
    return 0;
}
