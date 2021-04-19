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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)

ll a[100000<<2],b[100000<<2],n,m;
void build(int l,int r,int rt){
    if(l==r){cin>>a[rt];b[rt]=a[rt];return;}
    int m=l+r>>1;
    build(l,m,rt<<1),build(m+1,r,rt<<1|1);
    a[rt]=max(a[rt<<1],a[rt<<1|1]);
    b[rt]=min(b[rt<<1],b[rt<<1|1]);
}
pll query(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr){return mkp(a[rt],b[rt]);}
    ll m=l+r>>1;
    if(qr<=m) return query(l,m,ql,qr,rt<<1);
    else if(ql>m) return query(m+1,r,ql,qr,rt<<1|1);
    else{
        pll x=query(l,m,ql,qr,rt<<1),y=query(m+1,r,ql,qr,rt<<1|1);
        return mkp(max(x.F,y.F),min(x.S,y.S));
    }
}
int main(){
    oi;
    cin>>n>>m;
    build(0,n-1,1);
    while(m--){
        int x,y;
        cin>>x>>y;
        pll ans=query(0,n-1,x-1,y-1,1);
        cout<<ans.F-ans.S<<"\n";
    }
//    system("pause");
    return 0;
}
