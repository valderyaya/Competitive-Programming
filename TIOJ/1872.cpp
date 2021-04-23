//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll n,m,now=0;
struct qq{
    int l,r,id;
    bool operator<(const qq &a)const{
        return r<a.r;
    }
}q[1000001];
const ll mod=1e9+7;
ll power(ll a){
    ll res=1,n=mod-2;
    for(;n;n>>=1,a=a*a%mod) if(n&1) res=res*a%mod;
    return res%mod;
}
ll mip[1000001]={0,1},a[1000001],b[1000001],ans[1000001];
vector<ll> prime,p[1000001],invp[1000001];
vector<pii> st[1000001];
void build(){
    ll j;
    for(ll i=2;i<=1000000;i++){
        if(!mip[i]){
            prime.em(i);
            for(j=1,p[i].em(1),invp[i].em(1);i*p[i][j-1]<=1000000;j++) p[i].em(i*p[i][j-1]),invp[i].em(power(p[i][j]));
        }
        for(ll x : prime){
            if(i*x>1000000) break;
            mip[i*x]=x;
            if(i%x==0) break;
        }
    }
}
void modify(ll x,ll v){
    for(;x<=n;x+=lb(x)) b[x]=b[x]*v%mod;
}
ll query(ll x){
    ll res=1;
    for(;x;x-=lb(x)) res=res*b[x]%mod;
    return res;
}
void add(ll r){
    ll tmp=a[r],c,last,x;
    while(mip[tmp]>1){
        x=mip[tmp];last=0;
        for(c=0;tmp%x==0;tmp/=x) c++;
        while(!st[x].empty()){
            if(st[x].back().F>c){
                if(last!=c) modify(st[x].back().S,invp[x][c-last]);
                break;
            }else modify(st[x].back().S,invp[x][st[x].back().F-last]),last=st[x].back().F,st[x].pop_back();
        }
        st[x].em(mkp(c,r));modify(r,p[x][c]);
    }
    if(tmp>1){
        x=tmp,c=1,last=0;
        while(!st[x].empty()){
            if(st[x].back().F>c){
                if(last!=c) modify(st[x].back().S,invp[x][c-last]);
                break;
            }else modify(st[x].back().S,invp[x][st[x].back().F-last]),last=st[x].back().F,st[x].pop_back();
        }
        st[x].em(mkp(c,r));modify(r,p[x][c]);
    }
}
int main(){Rosario
    build();
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i],b[i]=1;
    REP(i,m) cin>>q[i].l>>q[i].r,q[i].id=i;
    sort(q,q+m);
    for(int i=0;i<m;){
        while(now<q[i].r) add(++now);
        while(i<m&&now==q[i].r){
            if(q[i].l==q[i].r) ans[q[i].id]=a[q[i].l],++i;
            else ans[q[i].id]=query(q[i].r)*power(query(q[i].l-1))%mod,++i;
        }
    }
    REP(i,m) cout<<ans[i]<<'\n';
//    system("pause");
    return 0;
}
