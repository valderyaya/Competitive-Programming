//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

set<int> t;
map<int,int> id;
int n,cnt=1,seg[1000005<<2],laz[1000005<<2];
struct qq{
    int x,y1,y2,w;
    bool operator<(const qq &a)const{
        return x==a.x?w<a.w:x<a.x;
    }
}qx[200005];
struct pp{int y1,y2,w;}p[100005];
void down(int rt){
    laz[rt<<1]+=laz[rt],laz[rt<<1|1]+=laz[rt];
    seg[rt<<1]+=laz[rt],seg[rt<<1|1]+=laz[rt];
    laz[rt]=0;
}
void modify(int l,int r,int ql,int qr,int rt,int x){
    if(laz[rt]&&l!=r) down(rt);
    if(ql<=l&&r<=qr){
        seg[rt]+=x;laz[rt]+=x;return;
    }int m=l+r>>1;
    if(ql<=m) modify(l,m,ql,qr,rt<<1,x);
    if(qr>m) modify(m+1,r,ql,qr,rt<<1|1,x);
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}
int main(){Rosario
    cin>>n;
    int x1,x2,y1,y2,ans=0,sum=0,v;
    REP(i,n){
        cin>>x1>>y1>>x2>>y2>>v;
        qx[i<<1]=qq{x1,y1,y2,v};qx[i<<1|1]=qq{x2+1,y1,y2,-v};
        p[i]=pp{y1,y2,v};t.insert(y1),t.insert(y2);
    }sort(qx,qx+n+n);
    for(int i:t) id[i]=cnt++;
    REP(i,n) modify(1,cnt,id[p[i].y1],id[p[i].y2],1,p[i].w);
    REP(i,n<<1){
        sum+=qx[i].w;
        modify(1,cnt,id[qx[i].y1],id[qx[i].y2],1,-qx[i].w);
        ans=max(ans,sum+seg[1]);
    }cout<<ans<<"\n";
//    system("pause");
    return 0;
}
