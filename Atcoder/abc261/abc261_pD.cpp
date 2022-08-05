#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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

const int z=5001;
ll n,m,f[z][z],a[z],c[z],mx;
signed main(){StarBurstStream
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i];
    for(int x,y,i=0;i<m;++i){
        cin>>x>>y;
        c[x]=y;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            f[i][j]=a[i]+c[j]+f[i-1][j-1];
            f[i][0]=max(f[i][0],f[i-1][j-1]);
        }
    }
    for(int i=1;i<=n;++i) mx=max(mx,f[n][i]);
    cout<<mx<<"\n";
}
