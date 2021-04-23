//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
#include "lib1871.h"
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
//#define lb(x) (x&-x)

const int z=1e6+5,inf=2147483647;
int seg[z<<2],n,q,*a;
void build(int l,int r,int rt){
    if(l==r) return seg[rt]=a[l-1],void();
    int mid=l+r>>1;
    build(l,mid,rt<<1);build(mid+1,r,rt<<1|1);
    seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1,re=inf;
    if(ql<=mid) re=query(l,mid,ql,qr,rt<<1);
    if(qr>mid) re=min(re,query(mid+1,r,ql,qr,rt<<1|1));
    return re;
}
int main(){
    n = futa::init();
    a = futa::momo_gives_you_list_of_futa();
    build(1,n,1); int l,r;
    q=futa::momo_tells_you_q();
    while(q--){
        tie(l,r)=futa::momo_asks();
        futa::you_tell_momo(query(1,n,l+1,r+1,1));
    }
}
