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

ll n,a[100005],st[100005],tp,ans;
signed main(){StarBurstStream
    while(cin>>n){
        ans = tp =0;
        REP(i,n) cin>>a[i];
        a[n]=-1;
        REP1(i,0,n){
            while(tp && a[st[tp]] >= a[i]){
                ll x=a[st[tp--]];
                ans = max(ans, (tp?i-st[tp]-1:i)*x);
            }
            st[++tp] = i;
        }
        cout<<ans<<"\n";
    }
}
