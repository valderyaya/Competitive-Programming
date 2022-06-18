#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

const int maxn=200005;
int n,m,rt[maxn],cnt=0;
struct qq{int l,r,v;}seg[maxn<<5];
void update(int &o,int pre,int l,int r,int idx,int val){
    o=++cnt;
    seg[o]=seg[pre];
    if(l==r) return seg[o].v=val,void();
    int mid=l+r>>1;
    if(idx<=mid) update(seg[o].l,seg[pre].l,l,mid,idx,val);
    else update(seg[o].r,seg[pre].r,mid+1,r,idx,val);
    seg[o].v=min(seg[seg[o].l].v,seg[seg[o].r].v);
}
int query(int root,int l,int r,int idx){
    if(l==r) return l;
    int mid=l+r>>1;
    if(seg[seg[root].l].v<idx) return query(seg[root].l,l,mid,idx);
    else return query(seg[root].r,mid+1,r,idx);
}
int main(){Rosario
    cin>>n>>m;
    int x,y;
    REP1(i,1,n) cin>>x,update(rt[i],rt[i-1],0,1e9,x,i);
    while(m--){
        cin>>x>>y;
        cout<<query(rt[y],0,1e9,x)<<"\n";
    }
//    system("pause");
    return 0;
}
