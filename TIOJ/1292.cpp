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

inline void rd(int &x){
    x=0;char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar_unlocked();
}
struct edge{int to,nxt;}e[20005];
int cnt=0,n,h[10005],dp[2][10005];
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x,int p){
    dp[0][x]=0,dp[1][x]=1;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==p) continue;
        dfs(v,x);
        dp[1][x]+=min(dp[1][v],dp[0][v]);
        dp[0][x]+=dp[1][v];
    }
}
void write(int x){
    if(!x) return;
    write(x/10);
    putchar_unlocked(x%10+'0');
}
int main(){//Rosario
    rd(n);int x,y;
    REP(i,n-1) rd(x),rd(y),add(x,y),add(y,x);
    dfs(1,0); write(min(dp[0][1],dp[1][1]));
    return 0;
}
