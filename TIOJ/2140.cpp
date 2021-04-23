//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

using namespace __gnu_pbds;
template <typename T> using rbt = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int z=1e5+5;
unordered_map<int,rbt<int>> mp;
int n,q;
inline void rd(int &x){
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
bitset<z<<2> zero;
#define ls rt<<1
#define rs rt<<1|1
int val[z<<2],cnt[z<<2];
void up(int rt){
    if(val[ls]==val[rs]) val[rt]=val[ls],cnt[rt]=cnt[ls]+cnt[rs];
    else if(cnt[ls]>cnt[rs]) val[rt]=val[ls],cnt[rt]=cnt[ls]-cnt[rs];
    else val[rt]=val[rs],cnt[rt]=cnt[rs]-cnt[ls];
    zero[rt]=zero[ls]&&zero[rs];
}
void build(int l,int r,int rt){
    if(l==r) return cin>>val[rt],cnt[rt]=1,mp[val[rt]].insert(l),zero[rt]=(val[rt]==0),void();
    int mid=l+r>>1;
    build(l,mid,ls),build(mid+1,r,rs);
    up(rt);
}
void modify(int l,int r,int ql,int qr,int rt,int x){
    if(zero[rt]) return;
    if(l==r) {
        if(val[rt]==0) return;
        return mp[val[rt]].erase(l),val[rt]/=x,mp[val[rt]].insert(l),zero[rt]=(val[rt]==0),void();
    }int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,ls,x);
    if(qr>mid) modify(mid+1,r,ql,qr,rs,x);
    up(rt);
}
void mod(int l,int r,int x,int rt,int v){
    if(l==r) return mp[val[rt]].erase(l),mp[val[rt]=v].insert(l),zero[rt]=(val[rt]==0),void();
    int mid=l+r>>1;
    if(x<=mid) mod(l,mid,x,ls,v);
    else mod(mid+1,r,x,rs,v);
    up(rt);
}
pii query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return mkp(val[rt],cnt[rt]);
    int mid=l+r>>1;
    if(qr<=mid) return query(l,mid,ql,qr,ls);
    else if(ql>mid) return query(mid+1,r,ql,qr,rs);
    pii res,L,R;
    L=query(l,mid,ql,qr,ls);
    R=query(mid+1,r,ql,qr,rs);
    if(L.F==R.F) res.F=L.F,res.S=L.S+R.S;
    else if(L.S>R.S) res.F=L.F,res.S=L.S-R.S;
    else res.F=R.F,res.S=R.S-L.S;
    return res;
} 
void write(int x){
    if(!x) return;
    write(x/10);
    putchar(x%10+'0');
}
int main(){//Rosario
    rd(n),rd(q);
    build(1,n,1);
    int k,l,r,x;
    while(q--){
        rd(x),rd(l),rd(r);
        if(x==1) mod(1,n,l,1,r);
        else if(x==2) {rd(k);
            if(k>1) modify(1,n,l,r,1,k);
        }else if(x==3){
            pii o=query(1,n,l,r,1);
            k=mp[o.F].order_of_key(r+1)-mp[o.F].order_of_key(l);
            if(k>=(r-l+3)/2){
                if(!o.F) puts("0");
                else write(o.F),putchar('\n');
            }else puts("-1");
        }
    }
    return 0;
}
