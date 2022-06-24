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

map<ll,ll> mp;
set<ll> sa,sb;
const ll N=4e5+5;
ll n,ha[200001],hb[200001],q,cnt;
ll hash_(ll x){
    if(mp.count(x)) return mp[x];
    return mp[x]=(++cnt)+N;
}
signed main(){valder
    cin>>n;
    for(ll x,i=1;i<=n;++i){
        cin>>x;
        x=hash_(x);
        ha[i]=ha[i-1];
        if(!sa.count(x)){
            ha[i]+=x;
            sa.insert(x);
        }
    }
    for(ll x,i=1;i<=n;++i){
        cin>>x;
        x=hash_(x);
        hb[i]=hb[i-1];
        if(!sb.count(x)){
            hb[i]+=x;
            sb.insert(x);
        }
    }
    cin>>q;
    for(ll x,y;q--;){
        cin>>x>>y;
        cout<<(ha[x]==hb[y]?"Yes":"No")<<"\n";
    }
}
