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

pii seg[200000<<2];
string s;
int n,m;
void build(int l,int r,int rt){
    if(l==r) return seg[rt].F=s[l-1]-'0',void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    seg[rt].F=seg[rt<<1].F+seg[rt<<1|1].F;
}
void down(int l,int r,int rt){
    if(l==r||seg[rt].S==0) return;
    int mid=l+r>>1;
    seg[rt<<1].S^=1,seg[rt<<1|1].S^=1;seg[rt].S=0;
    seg[rt<<1].F=mid-l+1-seg[rt<<1].F;
    seg[rt<<1|1].F=r-mid-seg[rt<<1|1].F;
}
void mod(int l,int r,int ql,int qr,int rt){
    down(l,r,rt);
    if(ql<=l&&r<=qr){
        seg[rt].F=r-l+1-seg[rt].F;
        seg[rt].S^=1;return;
    }int mid=l+r>>1;
    if(ql<=mid) mod(l,mid,ql,qr,rt<<1);
    if(qr>mid) mod(mid+1,r,ql,qr,rt<<1|1);
    seg[rt].F=seg[rt<<1].F+seg[rt<<1|1].F;
}
int que(int l,int r,int ql,int qr,int rt){
    down(l,r,rt);
    if(ql<=l&&r<=qr) return seg[rt].F;
    int mid=l+r>>1,sum=0;
    if(ql<=mid) sum+=que(l,mid,ql,qr,rt<<1);
    if(qr>mid) sum+=que(mid+1,r,ql,qr,rt<<1|1);
    return sum;
}
int main(){Rosario
    cin>>n>>m>>s;
    build(1,n,1);
    int a,b,k;
    while(m--){
        cin>>k>>a>>b;
        if(k) cout<<que(1,n,a,b,1)<<"\n";
        else mod(1,n,a,b,1);
    }
//    system("pause");
    return 0;
}
