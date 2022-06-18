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

ll n,q,a[200005],b[200005];
signed main(){valder
    cin>>n>>q;
    REP1(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    REP1(i,1,n) b[i]=b[i-1]+a[i];
    //REP1(i,1,n) cout<<a[i]<<" \n"[i==n];
    //REP1(i,1,n) cout<<b[i]<<" \n"[i==n];
    for(ll x;q--;){
        cin>>x;
        ll idx=lower_bound(a+1,a+1+n,x)-a-1;
        //cout<<idx<<"\n";
        cout<<b[n]-b[idx]-(n-idx)*x+idx*x-b[idx]<<"\n";
    }
    return 0;
}
