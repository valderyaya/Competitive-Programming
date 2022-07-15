//#pragma GCC optimize("O2")
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

const int z=200005;
ll n, q, X, p[z], cnt[z];
bitset<z> vis;
vector<ll> pack;
signed main(){StarBurstStream
    cin>>n>>q>>X;
    for(int i=1;i<=n;++i){
        cin>>p[i];
        p[i]+=p[i-1];
    }
    ll l=0;
    while(!vis[l]){
        vis[l]=1;
        pack.em(l);
        ll goal = p[l] + X;
        ll cys = goal / p[n];
        ll r = n * cys + (lower_bound(p+1, p+1+n, goal % p[n]) - p);
        cnt[l] = r - l;
        l = (r + n) % n;
    }
    ll start = find(ALL(pack), l) - pack.begin();
    ll cylen = pack.size() - start;
    for(ll k; q--; ){
        cin>>k, --k;
        if(k>=start){
            k -= start;
            k %= cylen;
            k += start;
        }
        cout<<cnt[pack[k]]<<"\n";
    }
}



