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


const ll mod=(1LL<<61)-1,z=100005;
ll t,n,k,a[z],b[z],c[z],dp[2][z];
void add(ll x,ll v){for(;x<z;x+=lb(x)) b[x]=(b[x]+v)%mod;}
ll que(ll x){
    ll res=0;
    for(;x;x-=lb(x)) res=(res+b[x])%mod;
    return res;
}
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n>>k;
        REP1(i,1,n) cin>>a[i],c[i]=a[i];
        c[0]=a[0]=0; sort(c,c+1+n);
        ll idx=unique(c,c+1+n)-c;
        REP1(i,0,n) dp[0][i]=dp[1][i]=0,a[i]=upper_bound(c,c+idx,a[i])-c;
        dp[0][0]=1;  ll now=1,pre=0,ans=0;
        REP1(i,1,k){
            memset(b,0,sizeof(b));
            REP1(j,0,n) dp[now][j]=0;
            REP1(j,1,n){
                add(a[j-1],dp[pre][j-1]);
                dp[now][j]=que(a[j]-1);
                ans=(ans+dp[now][j])%mod;
            }
            swap(now,pre);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
