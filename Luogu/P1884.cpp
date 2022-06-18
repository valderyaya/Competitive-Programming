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

struct qq{
    ll x,y1,y2,tag;
    bool operator<(const qq &a)const{
        return x<a.x;
    }
}q[4005];
ll n,x[4005],sum=0;
pll seg[4005<<2];
void up(ll l,ll r,ll rt){
    if(seg[rt].F) seg[rt].S=x[r+1]-x[l];
    else seg[rt].S=seg[rt<<1].S+seg[rt<<1|1].S;
}
void mod(ll l,ll r,ll ql,ll qr,ll rt,ll tag){
    if(ql<=l&&r<=qr){
        seg[rt].F+=tag;
        up(l,r,rt);return;   
    }ll m=l+r>>1;
    if(ql<=m) mod(l,m,ql,qr,rt<<1,tag);
    if(qr>m) mod(m+1,r,ql,qr,rt<<1|1,tag);
    up(l,r,rt);
}
int main(){Rosario
    cin>>n;
    ll x1,x2,y1,y2;
    REP1(i,1,n){
        cin>>x1>>y2>>x2>>y1;
        q[i]=qq{x1,y1,y2,1};
        q[i+n]=qq{x2,y1,y2,-1};
        x[i]=y1,x[i+n]=y2;
    }n<<=1;
    sort(q+1,q+1+n);sort(x+1,x+1+n);
    ll len=unique(x+1,x+1+n)-x-1;
    REP1(i,1,n-1){
        y1=lower_bound(x+1,x+1+len,q[i].y1)-x;
        y2=lower_bound(x+1,x+1+len,q[i].y2)-x;
        mod(1,len,y1,y2-1,1,q[i].tag);
        sum+=seg[1].S*(q[i+1].x-q[i].x);
    }
    cout<<sum<<"\n";
//    system("pause");
    return 0;
}
