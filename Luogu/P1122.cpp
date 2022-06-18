//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct edge{int to,nxt;}e[33000];
int n,cnt=0,h[16005],dp[16005],mx=0;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x,int p){
    for(int i=h[x];i;i=e[i].nxt) if(e[i].to!=p) dfs(e[i].to,x),dp[x]+=max(0,dp[e[i].to]);
    mx=max(mx,dp[x]);    
}
int main(){Rosario
    cin>>n; int x,y;
    REP1(i,1,n) cin>>dp[i];
    REP(i,n-1) cin>>x>>y,add(x,y),add(y,x);
    dfs(1,0); cout<<mx<<"\n";
    return 0;
}
