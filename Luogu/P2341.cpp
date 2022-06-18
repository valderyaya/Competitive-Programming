#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

struct edge{int to,nxt;}e[50005];
int n,col=0,c[10005],cnt=0,m,dfn[10005],tot,h[10005],low[10005],out[10005],s[10005];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
stack<int> st;
bitset<10005> in;
void dfs(int x){
    low[x]=dfn[x]=++tot;
    in[x]=1;st.emplace(x);
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!dfn[v]) dfs(v),low[x]=min(low[x],low[v]);
        else if(in[v]) low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x]){
        ++col;
        for(int u=0;u!=x;st.pop()) u=st.top(),in[u]=0,c[u]=col,s[col]++;
    }
}
int main(){Rosario
    cin>>n>>m;
    int a,b;
    REP(i,m) cin>>a>>b,add(a,b);
    REP1(i,1,n) if(!dfn[i]) dfs(i);
    REP1(i,1,n)
        for(int j=h[i];j;j=e[j].nxt)
            if(c[i]!=c[e[j].to]) out[c[i]]++;
    a=b=0;
    REP1(i,1,col) if(!out[i]) b=i,a++;
    cout<<(a==1?s[b]:0)<<"\n";
//    wait
    return 0;
}
