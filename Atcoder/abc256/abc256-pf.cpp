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

#define int ll
const ll mod=998244353, z=200005;
ll bit[3][z],n,q,a[z],inv;
void add(ll x,ll v){
    for(ll i=x;i<=n;i+=lb(i)){
        bit[0][i]+=v;
        bit[1][i]+=v*x%mod;
        bit[2][i]+=v*x%mod*x%mod;
        bit[0][i]%=mod;
        bit[1][i]%=mod;
        bit[2][i]%=mod;
        
    }
}
ll qry(ll x){
    ll res=0;
    for(ll i=x;i;i-=lb(i))
        (res+=bit[0][i]*(x+2)%mod*(x+1)%mod-(2*x+3)*bit[1][i]%mod+bit[2][i])%=mod;
    return (res%mod+mod)*inv%mod;
}
ll power(ll x,ll n){
    ll res=1;
    for(;n;n>>=1,x=x*x%mod) if(n&1) res=res*x%mod;
    return res;
}
signed main(){valder
    inv=power(2,mod-2);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        add(i,a[i]);
    }
    for(int op,x,v;q--;){
        cin>>op>>x;
        if(op==1){
            cin>>v;
            add(x,v-a[x]);
            a[x]=v;
        }else{
            cout<<qry(x)<<endl;
        }
    }
}
