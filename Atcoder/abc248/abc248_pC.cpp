#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

ll ans,n,m,k,f[51][2501];
const ll mod=998244353;
signed main(){valder
    cin>>n>>m>>k;
    f[0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            for(int l=k;l>=j;--l)
                f[i][l]=(f[i][l]+f[i-1][l-j])%mod;
    for(int i=n;i<=k;++i) ans=(ans+f[n][i])%mod;
    cout<<ans;
}
