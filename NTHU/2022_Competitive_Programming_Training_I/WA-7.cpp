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

const int z=1e5+5;
int n,f[3][z];
signed main(){StarBurstStream
    cin>>n;
    for(int a,b,c,i=1;i<=n;++i){
        cin>>a>>b>>c;
        f[0][i]=a+max(f[1][i-1],f[2][i-1]);
        f[1][i]=b+max(f[0][i-1],f[2][i-1]);
        f[2][i]=c+max(f[0][i-1],f[1][i-1]);
    }
    cout<<max({f[0][n],f[1][n],f[2][n]})<<"\n";
}
