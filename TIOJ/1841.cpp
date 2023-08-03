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

const int z=1e6+5;
ll a[z],t,n,b[z],l,r,L[z],R[z],c,ans;
signed main(){StarBurstStream
    cin>>t;
    while(t--){
        cin>>n;
        REP1(i,1,n) cin>>a[i],a[i]+=a[i-1];
        c=0;
        REP1(i,0,n){
            while(c&&a[b[c-1]]<=a[i]) R[b[--c]]=i;
            b[c++]=i;
        }
        while(c--) R[b[c]]=n+1;
        c=0;
        REP1(i,0,n){
            while(c&&a[b[c-1]]>a[i]) L[b[--c]]=i;
            b[c++]=i;
        }
        while(c--) L[b[c]]=n+1;
        l=r=ans=0;
        while(l<n){
            while(r<=n&&R[r]<L[l]) r=R[r];
            ans=max(ans,r-l);
            l=r=r+1;
        }cout<<ans<<"\n";
    }
}
