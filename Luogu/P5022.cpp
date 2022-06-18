//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct edge{int from,to,nxt;}e[10005];
int n,m,cnt,h[5005],ans[5005],tmp[5005],idx,U,V;
void add(int u,int v){
    e[++cnt]=edge{u,v,h[u]};
    h[u]=cnt;
}
vector<int> v[5005];
bitset<5005> vis;
bool ck(){
    REP1(i,1,n)
        if(tmp[i]<ans[i]) return 1;
        else if(tmp[i]>ans[i]) return 0;
    return 0;
}
inline void mdf(){
    REP1(i,1,n) ans[i]=tmp[i];
}
void dfs(int x,int p){
    if(vis[x]) return;
    tmp[++idx]=x; vis[x]=1;
    for(auto &i:v[x]){
        if(i==p||(x==V&&i==U)||(x==U&&i==V)) continue;
        dfs(i,x);
    }
}
void dfs2(int x,int p){
    ans[++idx]=x;
    for(auto &i:v[x]) if(i!=p) dfs2(i,x);
}
int main(){Rosario
    cin>>n>>m;
    for(int x,y,i=0;i<m;++i) {
        cin>>x>>y;
        add(x,y),add(y,x);
        v[x].em(y); v[y].em(x);
    }
    REP1(i,1,n) sort(ALL(v[i]));
    if(n==m){
        for(int i=1;i<=cnt;i+=2){
            U=e[i].from, V=e[i].to; idx=0;
            vis.reset();
            dfs(1,1);
            if(idx<n) continue;
            if(ans[1]==0||ck()) mdf();
        }
    }else dfs2(1,1);
    REP1(i,1,n) cout<<ans[i]<<" \n"[i==n];
    return 0;
}
