#include<bits/stdc++.h>
using namespace std;
#define lb(x) x&-x

const int maxn=100001;
int n, m, ls[maxn*400], rs[maxn*400], sum[maxn*400], a[maxn], b[maxn << 1], root[maxn], cnt, len;
vector<int> ql, qr;
struct query{
    int op, x, y, z;
}q[maxn];
void mdf(int l, int r, int x, int &o, int val){
    if(!o) o = ++cnt;
    sum[o] += val;
    if(l == r) return;
    int mid = l + r >> 1;
    if(x <= mid) mdf(l, mid, x, ls[o], val);
    else mdf(mid+1, r, x, rs[o], val);
}
void mdf_all(int x, int val){
    int idx = lower_bound(b+1, b+1+len, a[x]) - b;
    for(;x <= n; x += lb(x)) mdf(1, len, idx, root[x], val);
}
int qry(int l, int r, int k){
    if(l == r) return l;
    int mid = l + r >> 1, S = 0;
    for(auto &i:ql) S -= sum[ls[i]];
    for(auto &i:qr) S += sum[ls[i]]; 
    if(k <= S){
        for(int i=0,j=ql.size();i<j;++i) ql[i] = ls[ql[i]];
        for(int i=0,j=qr.size();i<j;++i) qr[i] = ls[qr[i]];
        return qry(l, mid, k);
    }else{
        for(int i=0,j=ql.size();i<j;++i) ql[i] = rs[ql[i]];
        for(int i=0,j=qr.size();i<j;++i) qr[i] = rs[qr[i]];
        return qry(mid+1, r, k - S);
    }
}
int qry_all(int l, int r, int k){
    ql.clear(), qr.clear();
    for(; r; r -= lb(r)) qr.emplace_back(root[r]);
    for(--l; l; l -= lb(l)) ql.emplace_back(root[l]);
    return qry(1, len, k);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        cin>>a[i], b[++len]=a[i];
    for(int i = 1; i <= m; ++i){
        char c; cin>>c;
        q[i].op = c=='Q';
        if(c == 'Q') cin >> q[i].x >> q[i].y >> q[i].z;
        else cin >> q[i].x >> q[i].y, b[++len]=q[i].y;
    }
    sort(b + 1, b + 1 + len);
    len = unique(b + 1, b + 1 + len) - b - 1;
    for(int i = 1; i <= n; ++i) mdf_all(i, 1);
    for(int i = 1; i <= m; ++i){
        if(q[i].op) cout << b[qry_all(q[i].x, q[i].y, q[i].z)] << "\n";
        else{
            mdf_all(q[i].x, -1);
            a[q[i].x] = q[i].y;
            mdf_all(q[i].x, 1);
        }
    }
    return 0;
}


