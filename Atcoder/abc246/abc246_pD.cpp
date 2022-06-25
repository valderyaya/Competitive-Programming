#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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

ll f(ll x,ll y){return x*x*x+x*x*y+x*y*y+y*y*y;}
ll n,i,j=1e6,ans=8e18;
signed main(){valder
    cin>>n;
    for(i=0;i<=1000000;++i){
        while(f(i,j)>=n&&j>=0){
            ans=min(ans,f(i,j));
            --j;
        }
    }
    cout<<ans;
}
