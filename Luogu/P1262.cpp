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

const int z=3005;
struct edge{int to,nxt;}e[8005];
int cnt=0,col[z],ez=0,n,m,s,dep[z],dfn=0,h[z],low[z],w[z],we[z],in[z];
bitset<z> ins;
stack<int> st;
inline void add(int u,int v){
    e[++ez]=edge{v,h[u]};
    h[u]=ez;
}
void dfs(int x){
    dep[x]=low[x]=++dfn;
    st.emplace(x); ins[x]=1;
    for(int i=h[x];i;i=e[i].nxt)
        if(!dep[e[i].to]) dfs(e[i].to),low[x]=min(low[x],low[e[i].to]);
        else if(ins[e[i].to]) low[x]=min(low[x],dep[e[i].to]);
    if(dep[x]==low[x]){we[++cnt]=1e9;
        for(int u=0;u!=x;st.pop()) u=st.top(),ins[u]=0,col[u]=cnt,we[cnt]=min(we[cnt],w[u]);
    }
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) w[i]=1e9;
    int a,b;
    while(m--) cin>>a>>b,w[a]=b;
    cin>>m;
    while(m--) cin>>a>>b,add(a,b);
    REP1(i,1,n) if(!dep[i]&&w[i]!=1e9) dfs(i);
    REP1(i,1,n) if(!dep[i]){cout<<"NO\n"<<i<<'\n'; return 0;}
    REP1(i,1,n) for(int j=h[i];j;j=e[j].nxt) if(col[i]!=col[e[j].to]) in[col[e[j].to]]++;
    int sum=0;
    REP1(i,1,cnt) if(!in[i]) sum+=we[i];
    cout<<"YES\n"<<sum<<'\n';
//    system("pause");
    return 0;
}
