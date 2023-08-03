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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long

ll n,k,sum,rem,a[1001],b[1001],m,ans;
signed main(){StarBurstStream
    while(cin>>n){
        ans=sum=rem=0;
        REP(i,n) cin>>a[i],sum+=a[i];
        cin>>k;
        REP(i,n){
            cin>>b[i];
            ans=max(ans,(b[i]+a[i]-1)/a[i]);
        }
        cin>>m;
        REP(i,n) rem+=a[i]*ans-b[i];
        m-=rem/k;
        rem%=k;
        if(m>0) ans+=(m*k+sum-1-rem)/sum;
        cout<<ans<<"\n";
    }
    return 0;
}
