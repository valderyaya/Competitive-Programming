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

#define int ll
const int z=2e5+5;
ll n,m,p1,p2,L[z],R[z],k[z],st[z],ans[z],tp,id1,id2,b1[z],b2[z];
void add(int x,int v){
    for(int i=x;i<=n;i+=lb(i)) b1[i]+=v,b2[i]+=x*v;
}
int qry(int x){
    int ret=0;
    for(int i=x;i;i-=lb(i)) ret+=(x+1)*b1[i]-b2[i];
    return ret;
}
struct que{
    int x,l,r,v,id;
    bool operator<(const que &o)const{return x<o.x;}
}q[z<<1];
struct qwq{
    int x,l,r,v;
    bool operator<(const qwq &o)const{return x<o.x;}
}p[z*3];
signed main(){StarBurstStream
    cin>>n>>m>>p1>>p2;
    REP1(i,1,n) cin>>k[i];
    st[tp]=0; k[0]=k[n+1]=n+1;  
    REP1(i,1,n){
        while(tp && k[st[tp]] < k[i]) --tp;
        L[i]=st[tp];
        st[++tp]=i;
    }
    st[tp=0]=n+1;
    for(int i=n;i;--i){
        while(tp && k[st[tp]] < k[i]) --tp;
        R[i]=st[tp];
        st[++tp]=i;
    }
    for(int i=1,l,r;i<=m;++i){
        cin>>l>>r;
        ans[i]=(r-l)*p1;
        q[++id1] = que{r,l,r,1LL,i};
        q[++id1] = que{l-1,l,r,-1LL,i};
    }
    sort(q+1,q+1+id1);
    //REP1(i,1,id1) cout<<q[i].x<<' '<<q[i].l<<' '<<q[i].r<<' '<<q[i].v<<' '<<q[i].id<<endl;
    REP1(i,1,n){
        if(L[i]&&R[i]<n+1) p[++id2]=qwq{R[i],L[i],L[i],p1};
        if(L[i]&&R[i]>i+1) p[++id2]=qwq{L[i],i+1,R[i]-1,p2};
        if(L[i]+1<i&&R[i]<n+1) p[++id2]=qwq{R[i],L[i]+1,i-1,p2};
    }
    sort(p+1,p+1+id2);
    for(int i=1,j=1;i<=id1;++i){
        while(j<=id2 && p[j].x <= q[i].x){
            //cout<<": "<<p[j].l<<' '<<p[j].r+1<<endl;
            add(p[j].l, p[j].v);
            add(p[j].r+1, -p[j].v);
            ++j;
        }
        ans[q[i].id]+=q[i].v*(qry(q[i].r)-qry(q[i].l-1));
        //cout<<ans[q[i].id]<<endl;
    }
    REP1(i,1,m) cout<<ans[i]<<"\n";
    return 0;
}
