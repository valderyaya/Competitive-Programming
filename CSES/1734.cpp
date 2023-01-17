#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
const int z=2e5+5;
int a[z],n,m,ans[z],bit[z],b[z],vis[z];
struct qwq{int l,r,id;}q[z];
void add(int x,int v){
    for(;x<=n;x+=lb(x)) bit[x]+=v;
}
int qry(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=bit[x];
    return res;
}
signed main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    int len=unique(b+1,b+1+n)-b;
    REP1(i,1,n) a[i]=upper_bound(b+1,b+len,a[i])-b;
    for(int l,r,i=1;i<=m;++i) cin>>q[i].l>>q[i].r,q[i].id=i;
    sort(q+1,q+1+m,[&](qwq x,qwq y){return x.r<y.r;});
    for(int now=1,i=1;i<=m;++i){
        while(now<=q[i].r){
            if(vis[a[now]]) add(vis[a[now]],-1);
            vis[a[now]]=now;
            add(now,1);
            ++now;
        }
        ans[q[i].id]=qry(q[i].r)-qry(q[i].l-1);
    }
    REP1(i,1,m) cout<<ans[i]<<"\n";
}
