//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long

const int z =1e6+5;
int seg[z<<2], laz[z<<2], n, m, c;
#define ls rt<<1
#define rs ls|1
void down(int rt){
    if(!laz[rt]) return;
    seg[ls] = seg[rs] = 1 << laz[rt];
    laz[ls] = laz[rs] = laz[rt];
    laz[rt] = 0;
}
void up(int rt){
    seg[rt]= seg[ls] | seg[rs];
}
void build(int l, int r, int rt){
    if(l==r) return seg[rt]=2,void();
    int mid = l+r>>1;
    build(l, mid, ls);
    build(mid+1, r, rs);
    up(rt);
}
void mdf(int l, int r, int ql, int qr, int rt, int k){
    if(ql<=l && r <= qr){
        laz[rt] = k;
        seg[rt] = 1<<k;
        return;
    }
    down(rt);
    int mid = l + r >> 1;
    if(ql<=mid) mdf(l, mid, ql, qr, ls, k);
    if(qr>mid) mdf(mid+1, r, ql, qr, rs, k);
    up(rt);
}
int qry(int l, int r, int ql, int qr, int rt){
    if(ql<=l && r<=qr) return seg[rt];
    down(rt);
    int mid=l+r>>1, ret = 0;
    if(ql<=mid) ret = qry(l,mid,ql,qr,ls);
    if(qr>mid) ret|=qry(mid+1,r,ql,qr,rs);
    return ret;
}
signed main(){StarBurstStream
    cin >> n >> c >> m;
    build(1, n, 1);
    char opt;
    for(int l, r, x; m--;){
        cin >> opt >> l >> r;
        if(l > r)swap(l,r);
        if(opt == 'C') cin >> x, mdf(1, n, l, r, 1, x);
        else{
            int ret = qry(1, n, l, r, 1), ans = 0;
            for(int i=1;i<=c;++i)
                if(ret >> i & 1) ++ans;
            cout << ans << "\n";
        }
    }
    return 0;
}
