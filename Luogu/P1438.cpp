#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define wait system("pause");

const int maxn=100005;
int n,m,a[maxn<<2],laz[maxn<<2],c[maxn];
void down(int l,int r,int rt){
    if(l==r||laz[rt]==0) return;
    int mid=l+r>>1;
    laz[rt<<1]+=laz[rt],laz[rt<<1|1]+=laz[rt];
    a[rt<<1]+=laz[rt]*(mid-l+1);
    a[rt<<1|1]+=laz[rt]*(r-mid);
    laz[rt]=0;
}
void modify(int l,int r,int ql,int qr,int rt,int x){
    down(l,r,rt);
    if(ql<=l&&r<=qr) return a[rt]+=(r-l+1)*x,laz[rt]+=x,void();
    int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1,x);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1,x);
    a[rt]=a[rt<<1]+a[rt<<1|1];
}
int que(int l,int r,int ql,int qr,int rt){
    down(l,r,rt);
    if(ql<=l&&r<=qr) return a[rt];
    int mid=l+r>>1;
    if(qr<=mid) return que(l,mid,ql,qr,rt<<1);
    else if(ql>mid) return que(mid+1,r,ql,qr,rt<<1|1);
    else return que(l,mid,ql,qr,rt<<1)+que(mid+1,r,ql,qr,rt<<1|1);
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>c[i];
    int x,l,r,k,d;
    while(m--){
        cin>>x;
        if(x==1){
            cin>>l>>r>>k>>d;
            modify(1,n,l,l,1,k);
            if(l<r) modify(1,n,l+1,r,1,d);
            if(r<n) modify(1,n,r+1,r+1,1,(l-r)*d-k);
        }else cin>>k,cout<<c[k]+que(1,n,1,k,1)<<"\n";
    }
//    system("pause");
    return 0;
}
