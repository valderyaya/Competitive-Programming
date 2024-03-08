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

ll n,a[21],cal=1e18;
signed main(){StarBurstStream
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<(1<<n);++i){
        ll c=0,d=0;
        for(int j=0;j<n;++j)
            if(i>>j&1) c+=a[j];
            else d+=a[j];
        cal=min(abs(c-d),cal);
    }
    cout<<cal<<"\n";
}
