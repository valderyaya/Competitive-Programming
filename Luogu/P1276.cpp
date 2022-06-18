#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct qq{
    int a[10005<<2],laz[10005<<2],cnt=0;
    void build(int l,int r,int rt){
        if(l==r) return a[rt]=1,void();
        int m=l+r>>1;
        build(l,m,rt<<1),build(m+1,r,rt<<1|1);
        a[rt]=a[rt<<1]+a[rt<<1|1];
    }
    void down(int l,int r,int rt){
        int m=l+r>>1;
        if(laz[rt]==1){
            laz[rt<<1]=laz[rt<<1|1]=1;
            a[rt<<1]=m-l+1,a[rt<<1|1]=r-m;
        }else if(laz[rt]==-1){
            laz[rt<<1]=laz[rt<<1|1]=-1;
            a[rt<<1]=a[rt<<1|1]=0;
        }laz[rt]=0;
    }
    void cut(int l,int r,int ql,int qr,int rt){
        if(ql<=l&&r<=qr) return cnt+=a[rt],laz[rt]=-1,a[rt]=0,void();
        down(l,r,rt);int m=l+r>>1;
        if(ql<=m) cut(l,m,ql,qr,rt<<1);
        if(qr>m) cut(m+1,r,ql,qr,rt<<1|1);
        a[rt]=a[rt<<1]+a[rt<<1|1];
    }
    void plant(int l,int r,int ql,int qr,int rt){
        if(ql<=l&&r<=qr) return laz[rt]=1,a[rt]=r-l+1,void();
        down(l,r,rt);int m=l+r>>1;
        if(ql<=m) plant(l,m,ql,qr,rt<<1);
        if(qr>m) plant(m+1,r,ql,qr,rt<<1|1);
        a[rt]=a[rt<<1]+a[rt<<1|1];
    }
}seg[2];
int n,m;
int main(){//Rosario
    cin>>n>>m;++n;
    seg[0].build(1,n,1),seg[1].build(1,n,1);
    for(int l,r,k,i=0;i<m;i++){
        cin>>k>>l>>r;r++,l++;
        if(k) seg[0].plant(1,n,l,r,1);
        else seg[0].cut(1,n,l,r,1),seg[1].cut(1,n,l,r,1);
    }cout<<seg[0].a[1]-seg[1].a[1]<<"\n"<<seg[0].cnt-seg[1].cnt<<"\n";
//    system("pause");
    return 0;
}
