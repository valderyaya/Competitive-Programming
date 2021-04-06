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

ll f[50][50][50],t,n,a[50],id;
ll dfs(ll pos,bool zr,bool lmt,ll cnt,ll now){
    if(pos<=0) return cnt*2>now;
    if(!zr&&!lmt&&~f[pos][cnt][now]) return f[pos][cnt][now];
    ll res=0,up=lmt?a[pos]:1;
    for(ll i=0;i<=up;++i)
        res+=dfs(pos-1,zr&&(i==0),lmt&&(i==up),cnt+i,now-(zr&&(i==0)));
    if(!zr&&!lmt) f[pos][cnt][now]=res;
    return res;
}
void solve(ll x){
    for(id=0;x;x>>=1) a[++id]=x%2;
    cout<<dfs(id,1,1,0,id)<<"\n";
}
signed main(){Rosario
    cin>>t;
    memset(f,-1,sizeof(f));
    while(t--){
        cin>>n;
        solve(n);
    }
    return 0;
}
