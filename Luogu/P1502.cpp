//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

#define int ll
const int z=1e5+5;
struct qwq{
    int x,l,r,v;
    bool operator<(const qwq &a){return x==a.x?v>a.v:x<a.x;}
}a[z<<1];
int seg[z<<4],laz[z<<2],n,t,w,h,c[z<<1],ans;
void init(){
    ans=0;
    memset(seg,0,sizeof(seg));
    memset(laz,0,sizeof(laz));
}
#define ls rt<<1
#define rs ls|1
void down(int rt){
    if(!laz[rt]) return;
    laz[ls]+=laz[rt], laz[rs]+=laz[rt];
    seg[ls]+=laz[rt], seg[rs]+=laz[rt];
    return laz[rt]=0,void();
}
void modify(int l,int r,int ql,int qr,int rt,int v){
    if(ql<=l&&r<=qr) return seg[rt]+=v,laz[rt]+=v,void();
    int mid=l+r>>1; down(rt);
    if(ql<=mid) modify(l,mid,ql,qr,ls,v);
    if(qr>mid) modify(mid+1,r,ql,qr,rs,v);
    seg[rt]=max(seg[ls],seg[rs]);
}
main(){Rosario
    cin>>t;
    int x,y,v;
    while(t--){
        init();
        cin>>n>>w>>h;
        REP1(i,1,n){
            cin>>x>>y>>v;
            a[i]=qwq{x,y,y+h-1,v};
            a[i+n]=qwq{x+w-1,y,y+h-1,-v};
            c[i]=y, c[i+n]=y+h-1;
        } n<<=1;
        sort(c+1,c+1+n); sort(a+1,a+1+n);
        int len=unique(c+1,c+1+n)-c;
        REP1(i,1,n){
            a[i].l=lower_bound(c+1,c+len,a[i].l)-c;
            a[i].r=lower_bound(c+1,c+len,a[i].r)-c;
            modify(1,len,a[i].l,a[i].r,1,a[i].v);
            ans=max(ans,seg[1]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
