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

const int z=1e4+5;
ll t,ans,l,r,mid,a[z],b[z],c[z],d[z],n,m;
bool ck(ll md){
    REP(i,n) d[i]=a[i]+b[i]*md;
    sort(d,d+n);
    ll i=0,j=0,cnt=0;
    for(;j<n;++j){
        while(i<n&&d[i]<=c[j]) ++i;
        if(i>=n) break;
        ++i; ++cnt;
    }
    return cnt>=m;
}
signed main(){StarBurstStream
    cin>>t;
    while(t--){
        cin>>n>>m;
        REP(i,n) cin>>a[i]>>b[i];
        REP(i,n) cin>>c[i];
        sort(c,c+n);
        l=0,r=1e9,ans=-1;
        while(l<r){
            mid=l+r>>1;
            if(ck(mid)){
                r=mid;
                ans=mid;
            }else l=mid+1;
        }
        cout<<ans<<'\n';
    }
}
