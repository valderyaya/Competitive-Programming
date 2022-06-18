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

ll n,m,h[40]={},cnt,ans=1e9;
map<ll,ll> mp;
signed main(){//valder
    cin>>n>>m;
    for(ll i=0;i<n;++i) h[i]=1LL<<i;
    //for(int i=0;i<n;++i) cout<<h[i]<<' ';
    for(ll x,y;m--;){
        cin>>x>>y;
        --x,--y;
        h[x]|=(1LL<<y);
        h[y]|=(1LL<<x);
    }
    ll goal=(1LL<<n)-1,mid=n>>1;
    for(ll i=0;i<(1<<mid);++i){
        ll cnt=0,state=0;
        for(int j=0;j<mid;++j){
            if(i>>j&1){
                ++cnt;
                state^=h[j];
            }
        }
        if(!mp.count(state)) mp[state]=cnt;
        else mp[state]=min(mp[state],cnt);
    }
    mid=n-mid;
    for(ll i=0;i<(1<<mid);++i){
        ll state=0,cnt=0;
        for(int j=0;j<mid;++j){
            if(i>>j&1){
                ++cnt;
                state^=h[n/2+j];
            }
        }
        if(mp.count(goal^state)) ans=min(ans,cnt+mp[goal^state]);
    }
    cout<<ans<<endl;
}
