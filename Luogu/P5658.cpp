//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)


const int z=5e5+5;
struct edge{int to,nxt;}e[z];
int cnt,n,h[z],fa[z];
ll ans,ed[z],f[z];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
char c[z];
stack<int> st;
void dfs(int x){
    int t=0;
    if(c[x]==')'){
        if(!st.empty()){
        t=st.top(); st.pop();
        ed[x]=ed[fa[t]]+1;}
    }else st.emplace(x);
    f[x]=f[fa[x]]+ed[x];
    ans^=f[x]*x;
    for(int i=h[x];i;i=e[i].nxt) dfs(e[i].to);
    if(t) st.emplace(t);
    else if(!st.empty()) st.pop();
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>c[i];
    for(int x,i=2;i<=n;++i){
        cin>>x;add(x,i);fa[i]=x;
    }dfs(1);cout<<ans<<"\n";
    return 0;
}
