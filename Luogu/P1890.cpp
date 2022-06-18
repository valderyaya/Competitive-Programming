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

int n,m,seg[1000<<2];
void build(int l,int r,int rt){
    if(l==r) return cin>>seg[rt],void();
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    seg[rt]=__gcd(seg[rt<<1],seg[rt<<1|1]);
}
int que(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1;
    if(qr<=mid) return que(l,mid,ql,qr,rt<<1);
    else if(ql>mid) return que(mid+1,r,ql,qr,rt<<1|1);
    else return __gcd(que(l,mid,ql,qr,rt<<1),que(mid+1,r,ql,qr,rt<<1|1));
}
int main(){Rosario
    cin>>n>>m;
    build(1,n,1);
    int a,b;
    while(m--) cin>>a>>b,cout<<que(1,n,a,b,1)<<"\n";
//    system("pause");
    return 0;
}
