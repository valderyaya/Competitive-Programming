#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

const int z=1e5+5;
int t,pa[z],n,tp[2],cnt;
struct qwq{
    int l,r,c;
    bool operator<(const qwq &x)const{return r^x.r?r<x.r:(l^x.l?l<x.l:c<x.c);}
    bool operator==(const qwq &x)const{return l==x.l&&r==x.r&&c==x.c;}
}a[z],st[2][z];
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void un(int x,int y){
    x=fin(x), y=fin(y);
    if(x!=y) pa[x]=y,--cnt;
}
void sol(int c,int l,int r,int id){
    qwq tmp = tp[c]? st[c][tp[c]] : qwq{-1,-1,-1};
    while(tp[c] && st[c][tp[c]].r>=l) un(st[c][tp[c]].c, id), --tp[c];
    if(tmp.c!=-1 && (!tp[c] || !(st[c][tp[c]]==tmp))) st[c][++tp[c]]=tmp;
    st[c^1][++tp[c^1]]=qwq{l,r,id};
}
signed main(){StarBurstStream
    cin>>t;
    while(t--){
        cin>>n;
        tp[0]=tp[1]=0, cnt=n;
        for(int i=0;i<n;++i){
            cin>>a[i].c>>a[i].l>>a[i].r;
            pa[i]=i;
        }
        sort(a,a+n);
        for(int i=0;i<n;++i) sol(a[i].c^1,a[i].l,a[i].r,i);
        cout<<cnt<<"\n";
    }
}
