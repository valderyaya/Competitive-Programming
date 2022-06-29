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


const ll mod=998244353;
ll ans,f[2][10],now=1,n;
signed main(){valder
    cin>>n;
    for(int i=1;i<10;++i) f[0][i]=1;
    for(int i=1;i<n;++i){
        for(int j=1;j<10;++j){
            f[now][j]=f[now^1][j];
            if(j-1>0) (f[now][j]+=f[now^1][j-1])%=mod;
            if(j+1<10) (f[now][j]+=f[now^1][j+1])%=mod;
        }
        now^=1;
    }
    now^=1;
    for(int i=1;i<10;++i) (ans+=f[now][i])%=mod;
    cout<<ans;
}
