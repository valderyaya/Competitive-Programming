//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";
 
ll t,n,mod,seg[100001<<2],a[100001],x;
void build(ll l,ll r,ll rt){
    if(l==r) return seg[rt]=1,void();
    ll m=l+r>>1;
    build(l,m,rt<<1),build(m+1,r,rt<<1|1);
    seg[rt]=seg[rt<<1]*seg[rt<<1|1]%mod;
}
void modify(ll l,ll r,ll rt,ll x,ll y){
    if(l==r&&l==x) return seg[rt]=y,void();
    ll m=l+r>>1;
    if(x<=m) modify(l,m,rt<<1,x,y);
    else if(x>m) modify(m+1,r,rt<<1|1,x,y);
    seg[rt]=seg[rt<<1]*seg[rt<<1|1]%mod;
}
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n>>mod;
        build(1,n,1);
        REP1(i,1,n){
            cin>>x>>a[i];
            if(x==1) modify(1,n,1,i,a[i]);
            else modify(1,n,1,a[i],1);
            cout<<seg[1]<<"\n";
        }
    }
//    system("pause");
    return 0;
}
