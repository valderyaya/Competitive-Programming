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
#define endl "\n"


ll a,b,k;
signed main(){valder
    cin>>a>>b>>k;
    if(a>=b) return cout<<0,0;
    for(ll cnt=1;;++cnt){
        a*=k;
        if(a>=b) return cout<<cnt,0;
    }
}
