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

int n,m,a[11];
signed main(){StarBurstStream
    cin>>n>>m;
    for(int i=1;i<=n;++i) a[i]=i;
    while(1){
        for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
        if(a[n]==m&&a[n]-a[1]==n-1) break;
        int i,j=0;
        for(i=n;i;--i,++j)
            if(a[i]!=m-j){
                ++a[i];
                break;
            }
        for(++i;i<=n;++i) a[i]=a[i-1]+1;
    }
}
