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


inline int read() {
    int ret=0,f=1;char ch=getchar_unlocked();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
    while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
    return ret*f;
}
int n,m,seg[1000000<<2],laz[1000000<<2];
void build(int l,int r,int rt){
    if(l==r){seg[rt]=read();return;}
    int mid=l+r>>1;
    build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
    seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}
void down(int l,int r,int rt){
    laz[rt<<1]+=laz[rt],laz[rt<<1|1]+=laz[rt];
    seg[rt<<1]+=laz[rt],seg[rt<<1|1]+=laz[rt];
    laz[rt]=0;
}
void mod(int l,int r,int ql,int qr,int rt,int x){
    if(l!=r&&laz[rt]) down(l,r,rt);
    if(ql<=l&&r<=qr){
        seg[rt]+=x;laz[rt]+=x;return;
    }int mid=l+r>>1;
    if(ql<=mid) mod(l,mid,ql,qr,rt<<1,x);
    if(qr>mid) mod(mid+1,r,ql,qr,rt<<1|1,x);
    seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}
int main(){//Rosario
    n=read(),m=read();int x,l,r;
    build(1,n,1);
    REP(i,m){
        x=read(),l=read(),r=read();
        mod(1,n,l,r,1,-x);
        if(seg[1]<0){x=-1e9;puts("-1");printf("%d",i+1);break;}
    }
    if(x!=-1e9) puts("0");
//    system("pause");
    return 0;
}
