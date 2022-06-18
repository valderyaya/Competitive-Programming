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

ll x,a,d,n;
signed main(){valder
    cin>>x>>a>>d>>n;
    if(!d) return cout<<abs(x-a),0;
    ll t1=(x-a)/d,t2=t1+1;
    if(t2<=0) cout<<abs(a-x);
    else if(t1>=n) cout<<abs(x-a-n*d+d);
    else cout<<min(abs(x-a-d*t1),abs(x-a-d*t2));
}
