#include<bits/stdc++.h>
using namespace std;

const int z=1e5+1, maxn=1e9;
int ls[z<<5], rs[z<<5], rt[z], n, m, cnt, sum[z<<5];
void modify(int &o, int prv, int l, int r, int x, int v){
    o = ++cnt;
    ls[o] = ls[prv], rs[o] = rs[prv], sum[o]=sum[prv]+v;
    if(l==r) return;
    int mid=l+r>>1;
    if(x<=mid) modify(ls[o], ls[prv], l, mid, x, v);
    else modify(rs[o], rs[prv], mid+1, r, x, v);
}
int query(int L, int R, int l, int r, int ql, int qr){
    if(ql<=l && r<= qr) return sum[R] - sum[L];
    int mid =l+r>>1, res=0;
    if(ql<=mid) res = query(ls[L], ls[R], l, mid, ql, qr);
    if(qr>mid) res+= query(rs[L], rs[R], mid+1, r, ql, qr);
    return res;
}
signed main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int x, i = 1; i<=n; ++i){
        cin >> x;
        modify(rt[i], rt[i-1], 1, maxn, x, x);
    }
    //for(int i=1;i<=n;++i) cout<<rt[i]<<" \n"[i==n];
    cin >> m;
    for(int l, r, ans, ret; m--; ){
        ans = 1;
        cin>>l>>r;
        while(1){
            ret = query(rt[l-1], rt[r], 1, maxn, 1, ans);
            if(ret >= ans) ans = ret + 1;
            else break;
        }
        cout << ans <<"\n";
    }
}
