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

ll f[505][505],n,a[505];
const ll mod=998244353;
signed main(){valder
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i], f[i][i]=f[i+1][i]=1;
    for(int len =2;len<=n;++len){
        for(int i=1;i<=n-len+1;++i){
            int j=i+len-1;
            f[i][j]=f[i+1][j]%mod;
            for(int k=i+1;k<=j;++k){
                if(a[i]<a[k]) f[i][j]=(f[i][j]+f[i+1][k-1]*f[k][j]%mod)%mod;
            }
        }
    }
    cout<<f[2][n];
}
