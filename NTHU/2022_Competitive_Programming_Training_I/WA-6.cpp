//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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

const int z=5005;
ll n,f[z][z],a[z];
signed main(){StarBurstStream
    cin>>n;
    REP1(i,1,n) cin>>a[i],f[i][i]=a[i],a[i]+=a[i-1];
    for(int j=1;j<=n;++j) for(int i=j-1;i>0;--i){
        if(i==j-1) f[i][j]=max(a[i]-a[i-1],a[j]-a[j-1]);
        else f[i][j]=max(a[i]-a[i-1]+a[j]-a[i]-f[i+1][j], a[j]-a[j-1]+a[j-1]-a[i-1]-f[i][j-1]);
    }
    cout<<f[1][n]<<"\n";
}
