//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define ll long long
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

#define ll __int128_t
pair<ll,ll> inv_gcd(ll a,ll b){
    a%=b;
    if(a<0) a+=b;
    if(!a) return {b,0};
    ll s=b,t=a,m0=0,m1=1;
    while(t){
        ll u = s/t;
        s-=t*u;
        m0-=m1*u;
        swap(s,t);
        swap(m0,m1);
    }
    if(m0<0)m0+=b/s;
    return {s,m0};
}

pair<ll, ll> crt(const vector<ll>& r, const vector<ll>& m) {
    int n = r.size();
    ll r0 = 0, m0 = 1;
    for(int i = 0; i < n; i++) {
        ll r1 = r[i] % m[i];
        if(r1 < 0) r1 += m[i];
        ll m1 = m[i];
        if(m0 < m1) {
            swap(r0, r1);
            swap(m0, m1);
        }
        if(m0 % m1 == 0) {
            if(r0 % m1 != r1) return {0, 0};
            continue;
        }
        ll g, im;
        tie(g, im) = inv_gcd(m0, m1);
        ll u1 = (m1 / g);
        if((r1 - r0) % g) return {0, 0};
        ll x = (r1 - r0) / g % u1 * im % u1;
        r0 += x * m0;
        m0 *= u1;
        if(r0 < 0) r0 += m0;
    }
    return {r0, m0};
}
int n;
signed main(){StarBurstStream
    cin>>n;
    while(n--){
        vector<ll> r,m;
        for(int x,y,i=0;i<3;++i){
            cin>>x>>y;
            r.em(y);
            m.em(x);
        }
        long long x=crt(r,m).F;
        cout<<x<<"\n";
    }
}
