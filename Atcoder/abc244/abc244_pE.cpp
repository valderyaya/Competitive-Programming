#pragma GCC optimize("O2")
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

const ll mod = 998244353;
ll n,m,st,ed,pt,k,f[2][2005][2005];
vector<int> v[2005];
signed main(){valder
    cin>>n>>m>>k>>st>>ed>>pt;
    for(int x,y;m--;){
        cin>>x>>y;
        v[x].em(y);
        v[y].em(x);
    }
    f[0][0][st]=1;
    for(int i=1;i<=k;++i)
        for(int j=1;j<=n;++j)
            for(auto &u:v[j])
                for(int l=0;l<2;++l)
                    if(u==pt) (f[l][i][j]+=f[1-l][i-1][u])%=mod;
                    else (f[l][i][j]+=f[l][i-1][u])%=mod;
    cout<<f[0][k][ed]<<"\n";
}

