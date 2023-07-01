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
int t,n,b,pa[z],l[z],r[z],a[2][z];
signed main(){StarBurstStream
    cin>>t>>b;
    while(t--){
        cin>>n;
        int ans=0,minr=1e9+5,maxl=0;
        REP1(i,2,n) cin>>pa[i];
        REP1(i,1,n){
            cin>>l[i]>>r[i];
            minr = min(minr, r[i]);
            maxl = max(maxl, l[i]);
            if(pa[i]){
                a[0][i]=max(a[0][pa[i]],l[i]);
                a[1][i]=min(a[1][pa[i]],r[i]);
            }else a[0][i]=l[i], a[1][i]=r[i];
            ans = max(ans, a[0][i]-a[1][i]);
        }
        ans = max(ans, (maxl-minr+1)/2);
        cout<<ans<<"\n";
        if(!b) continue;
        if(maxl<=minr){
            REP1(i,1,n) cout<<maxl<<" \n"[i==n];
            continue;
        }
        int mid = (maxl + minr)/2;
        REP1(i,1,n) cout<<max(min(mid,r[i]),l[i])<<" \n"[i==n];
    }
    return 0;
}
