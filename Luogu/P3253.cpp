//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

struct qwq{
    int v,p;
    bool operator<(const qwq &x){return v>x.v;}
}a[100005];
ll ans;
int n,m,b[100005],now;
void add(int x,int v){for(;x<=n+m;x+=lb(x))b[x]+=v;}
int que(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=b[x];
    return res;
}
signed main(){Rosario
    cin>>n>>m; now=n;
    for(int i=n;i;--i) cin>>a[i].v;
    for(int i=n+1;i<=n+m;++i) cin>>a[i].v;
    REP1(i,1,n+m) a[i].p=i,add(i,1);
    sort(a+1,a+1+n+m);
    REP1(i,1,n+m){
        int x=a[i].p;
        if(now<x){
            ans+=que(x-1)-que(now);
            now=x-1;
        }else{
            ans+=que(now)-que(x);
            now=x;
        }
        add(x,-1);
    }cout<<ans<<'\n';
    return 0;
}
