#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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

inline void read(int &ret){
    ret=0;char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') ret=(ret<<3)+(ret<<1)+(c^48),c=getchar_unlocked();
}

const int maxn=500001;
int tri[2][3*maxn],ed[3*maxn],cnt[3*maxn],rt;

inline int node(){
    ++rt;
    tri[0][rt]=tri[1][rt]=ed[rt]=cnt[rt]=0;
    return rt;
}

inline void insert(int x,int id){
    int u=0,c;
    for(int i=19;~i;--i){
        c=((x>>i)&1);
        if(!tri[c][u]) tri[c][u]=node();
        u=tri[c][u];
        ++cnt[u];
    }
    ed[u]=id;
}

inline int find(int x,int sum){
    int u=0,c;
    for(int i=19;~i;--i){
        c=((x>>i)&1)^1;
        if(tri[c][u]&&cnt[tri[c][u]]>=sum) u=tri[c][u];
        else {
            if(tri[c][u]) sum-=cnt[tri[c][u]];
            u=tri[c^1][u];
        }
    }
    return ed[u];
}

int n,m,low[maxn],dfn[maxn],col[maxn],w[maxn],t,cl,star,r[maxn];
ll W[maxn],mx;
vector<int> v1[maxn],v2[maxn],st;
bitset<maxn> in;

void dfs(int x){
    low[x]=dfn[x]=++t;st.em(x);in[x]=1;
    for(auto &i:v1[x])
        if(!dfn[i]) dfs(i),low[x]=min(low[x],low[i]);
        else if(in[i]&&dfn[i]<dfn[x]) low[x]=min(low[x],dfn[i]);
    if(dfn[x]==low[x]){++cl;
        for(int u=0;u!=x;st.pop_back()) u=st.back(),in[u]=0,col[u]=cl,W[cl]+=w[u];
    }
}

void dfs2(int x, ll val){
    mx=max(mx, val);
    for(auto &i:v2[x]) dfs2(i, val+W[i]);
}

int main(){
    read(n),read(star);
    REP1(i,1,n) read(w[i]);
    REP1(i,1,n){
        read(m),read(r[i]);
        REP1(j,1,m){
            int x=find(w[i],j);
            v1[i].em(x);
        }
        insert(w[i],i);
    }
    rt=-1;
    node();
    for(int i=n;i>0;--i){
        REP1(j,1,r[i]){
            int x=find(w[i],j);
            v1[i].em(x);
        }
        insert(w[i],i);
    }
    dfs(star);
    REP1(i,1,n) for(auto &j:v1[i]) if(col[i]!=col[j]) v2[col[i]].em(col[j]);
    dfs2(col[star], W[col[star]]);
    printf("%lld\n",mx);
    return 0;
}
