#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define pii pair<long long,long long>
#define mkp make_pair
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define lb(x) (x&(-x)) 

vector<ll> v;
ll n,a[500050],b[500050];
inline void add(ll k){
    for(;k<500050;k+=lb(k)) b[k]++;
}
inline ll get(ll x){
    int sum=0;
    for(;x;x-=lb(x)) sum+=b[x];
    return sum;
}
int main(){
    oi;
    ll cnt=1;
    while(cin>>n and n){
        v.clear();
        for(int i=0 ; i<=500000 ; ++i) b[i] = 0;
        REP(i,n){
            cin>>a[i];
            v.em(a[i]);
        }
        sort(ALL(v));
        v.resize( unique(ALL(v))-v.begin());
        REP(i,n) a[i]=lower_bound(ALL(v),a[i])-v.begin()+1;
        ll ans=0;
        REP(i,n){
            add(a[i]);
            ans+=i-get(a[i])+1;
            //cout << get(a[i]) << '\n';
        }
        cout << "Case #"<<cnt++<<": "<< ans <<  '\n';
    }

//    system("pause");
    return 0;
}
