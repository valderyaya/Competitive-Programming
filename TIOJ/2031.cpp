#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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
#define wait system("pause");

inline void read(int &ret){
    ret=0;char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') ret=(ret<<3)+(ret<<1)+(c^48),c=getchar_unlocked();
}

const int maxn=500001;
int tri[20*maxn][2],ed[20*maxn],cnt[20*maxn],rt;

inline int node(){
    ++rt;
    tri[rt][0]=tri[rt][1]=ed[rt]=cnt[rt]=0;
    return rt;
}

inline void insert(int x,int id){
    int u=0,c;
    for(int i=19;~i;--i){
        c=((x>>i)&1);
        if(!tri[u][c]) tri[u][c]=node();
        u=tri[u][c];
        cnt[u]++;
    }
    ed[u]=id;
}

inline int find(int x,int sum){
    int u=0,c;
    for(int i=19;~i;--i){
        c=((x>>i)&1)^1;
        if(tri[u][c]&&cnt[tri[u][c]]>=sum) u=tri[u][c];
        else {
            if(tri[u][c]) sum-=cnt[tri[u][c]];
            u=tri[u][c^1];
        }
    }
    return ed[u];
}

int n,m,low[maxn],dfn[maxn],col[maxn],w[maxn],t=1,cl=0,star,r[maxn];
ll W[maxn];
vector<int> v1[maxn],v2[maxn];
stack<int> st;
bitset<maxn> in;

void dfs(int x){
    low[x]=dfn[x]=t++;st.emplace(x);in[x]=1;
    for(auto &i:v1[x])
        if(!dfn[i]) dfs(i),low[x]=min(low[x],low[i]);
        else if(in[i]&&dfn[i]<dfn[x]) low[x]=min(low[x],dfn[i]);
    if(dfn[x]==low[x]){++cl;
        for(int u=0;u!=x;st.pop()) u=st.top(),in[u]=0,col[u]=cl,W[cl]+=w[u];
    }
}

int main(){Rosario
    read(n),read(star);
    rt=-1;
    node();
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
    queue<pll> q;
    q.emplace(mkp((ll)col[star],W[col[star]]));
    ll mx=0;
    pll x;
    while(!q.empty()){
        x=q.front();q.pop();
        mx=max(mx,x.S);
        for(auto &i:v2[x.F]) q.emplace(mkp(i,x.S+W[i]));
    }
    cout<<mx<<"\n";
//    system("pause");
    return 0;
}
