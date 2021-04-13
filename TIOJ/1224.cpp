#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
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

struct qq{
    int tag,y1,y2,x;
    bool operator<(const qq &a)const{
        return x<a.x;
    }
}q[200005];
int n,x[200005],a[100005<<2],v[100005<<2];
ll sum=0;
void up(int l,int r,int rt){
    if(a[rt]) v[rt]=x[r+1]-x[l];
    else v[rt]=v[rt<<1]+v[rt<<1|1];
}
void modify(int l,int r,int ql,int qr,int rt,int x){
    if(ql<=l&&r<=qr){
        a[rt]+=x;up(l,r,rt);
        return;
    }int m=l+r>>1;
    if(ql<=m) modify(l,m,ql,qr,rt<<1,x);
    if(qr>m) modify(m+1,r,ql,qr,rt<<1|1,x);
    up(l,r,rt);
}
int main(){Rosario
    int x1,y1,x2,y2;
    cin>>n;
    REP1(i,1,n){
        cin>>x1>>x2>>y1>>y2;
        q[i]=qq{1,y1,y2,x1},q[i+n]=qq{-1,y1,y2,x2};
        x[i]=y1,x[i+n]=y2;
    }n<<=1;
    sort(x+1,x+1+n);sort(q+1,q+1+n);
    int c=unique(x+1,x+1+n)-x-1;
    REP1(i,1,n-1){
        y1=lower_bound(x+1,x+1+c,q[i].y1)-x;
        y2=lower_bound(x+1,x+1+c,q[i].y2)-x;
        modify(1,c,y1,y2-1,1,q[i].tag);
        sum+=(ll)(q[i+1].x-q[i].x)*v[1];
    }cout<<sum<<"\n";
//    system("pause");
    return 0;
}
