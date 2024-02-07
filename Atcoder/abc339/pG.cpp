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

#define int ll
const int z=2e5+5, inf=1e18;
int root[z], seg[z<<6], ls[z<<6], rs[z<<6], n, m, cnt;
void mdf(int &o, int pre, int l, int r, int x){
    o = ++cnt;
    ls[o] = ls[pre], rs[o] = rs[pre], seg[o] = seg[pre] + x;
    if(l==r) return;
    int mid = (r-l)/2 + l ;
    if(x<=mid) mdf(ls[o], ls[pre], l, mid, x);
    else mdf(rs[o], rs[pre], mid+1, r, x);
}
int qry(int l, int r, int ql, int qr, int L, int R){
    if(ql<=l && r<=qr) return seg[R] - seg[L];
    int mid= (r-l)/2 + l , ret=0;
    if(ql<=mid) ret=qry(l, mid, ql, qr, ls[L], ls[R]);
    if(qr>mid) ret+=qry(mid+1, r, ql, qr, rs[L], rs[R]);
    return ret;
}

signed main(){StarBurstStream
    cin>>n;
    for(int x, i=1; i<=n; ++i){
        cin >> x;
        mdf(root[i], root[i-1], 1, inf, x);
    }
    cin >> m;
    int x = 0, l, r, y;
    while(m--){
        cin >> l >> r >> y;
        //cout << l << ' ' << r << ' ' << y  << endl;
        l^=x, r^=x, y^=x;
        //cout << l << ' ' << r << ' ' << y  << endl;
        if(y) x = qry(1, inf, 1, y, root[l-1], root[r]);
        else x = 0;
        cout << x << "\n";
    }
}
