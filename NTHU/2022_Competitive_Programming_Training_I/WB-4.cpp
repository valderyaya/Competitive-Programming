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

int n;
struct qwq{
    int x,y,z;
    bool operator<(const qwq &o)const{return x<o.x;}
}a[200001];
ll ans,dp[400004];
vector<int> v;
signed main(){StarBurstStream
    cin>>n;
    REP(i,n){
        cin>>a[i].x>>a[i].y>>a[i].z;
        v.em(a[i].x), v.em(a[i].y);
    }
    sort(a,a+n);
    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());
    for(int i=0,j=0,k,l;i<n;++i){
        while(k=lower_bound(ALL(v),a[i].x)-v.begin(), j<k) ++j, dp[j]=max(dp[j],dp[j-1]);
        l=lower_bound(ALL(v),a[i].y)-v.begin()+1;
        dp[l]=max(dp[l],dp[k]+a[i].z);
        ans=max(ans,dp[l]);
    }cout<<ans<<"\n";
}
