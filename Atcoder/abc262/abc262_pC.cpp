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

ll n,a[500001],b,c;
signed main(){StarBurstStream
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]==i) ++b;
        else if(a[a[i]]==i) ++c;
    }
    cout<<b*(b-1)/2+c;
}
