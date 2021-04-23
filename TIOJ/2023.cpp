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
#define lb(x) (x&-x)

ll n,m,f[4194310];
void dp(ll l,ll r){
    if(l==r) return;
    ll mid=l+r>>1;
    dp(l,mid),dp(mid+1,r);
    for(int i=mid+1,j=l;i<=r;++i,++j) f[i]+=f[j];
}
int main(){Rosario
    cin>>n>>m;
    string s;
    ll x,y;
    while(m--){
        cin>>s>>x;
        y=0;
        for(int i=s.size()-1,j=0;i>=0;--i,++j) if(s[i]=='1') y|=(1<<j);
        f[y]=x;
    }
    dp(0,(1<<n)-1);
    sort(f+1,f+(1<<n));
    ll ans=0;
    REP1(i,1,(1<<n)) ans+=f[i]*i;
    cout<<ans;
    return 0;
}
