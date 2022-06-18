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
#define lb(x) (x&-x)

const int z=1e5+5;
struct edge{int to,nxt;}e[z];
int bit[z],a[z],c[z],cnt,n,h[z],ans[z];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void mod(int x){for(;x<=n;x+=lb(x)) bit[x]++;}
int que(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=bit[x];
    return res;
}
void dfs(int x){
    ans[x]-=que(a[x]);
    for(int i=h[x];i;i=e[i].nxt) dfs(e[i].to);
    ans[x]+=que(a[x]);
    mod(a[x]);
}
bool cmp(int x,int y){return a[x]>a[y];}
int main(){Rosario
    cin>>n;
    int x;
    REP1(i,1,n) cin>>a[i],c[i]=i;
    for(int i=2;i<=n;i++) cin>>x,add(x,i);
    sort(c+1,c+1+n,cmp);
    REP1(i,1,n) a[c[i]]=i;
    dfs(1);
    REP1(i,1,n) cout<<ans[i]<<"\n";
    return 0;
}
