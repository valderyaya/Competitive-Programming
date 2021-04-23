//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)

const ll maxn=22005,maxm=250005;

inline void rd(int &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
}

inline void rdll(ll &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
}

struct query{
    int x1,x2,y1,y2,opt;
    ll val;
}qry[maxn+maxm];

//-----------------------------------------------------------------

struct disct{
    int idx=0,idy=0,vy[maxn],vx[maxn+maxm*2];
    void addx(int x){vx[++idx]=x;}
    void addy(int x){vy[++idy]=x;}
    void unq(){
        sort(vx+1,vx+1+idx);
        sort(vy+1,vy+1+idy);
        idx=unique(vx+1,vx+1+idx)-vx-1;
        idy=unique(vy+1,vy+1+idy)-vy-1;
    }
    int getx(int x){return lower_bound(vx+1,vx+1+idx,x)-vx;}
    int gety(int x){return lower_bound(vy+1,vy+1+idy,x)-vy;}
}dis;

//-----------------------------------------------------------------

struct segment{
    int l,r;
    ll val;
}seg[maxn<<9];

int p[(maxn+maxm*2)<<2],cnt=0,q;

void mge(int l,int r,int a,int b,int &rt,int x){
    if(!rt) rt=++cnt;
    if(l==r) return seg[rt].val=__gcd(seg[a].val,seg[b].val),void();
    int mid=l+r>>1;
    if(x<=mid) mge(l,mid,seg[a].l,seg[b].l,seg[rt].l,x);
    else mge(mid+1,r,seg[a].r,seg[b].r,seg[rt].r,x);
    seg[rt].val=__gcd(seg[seg[rt].l].val,seg[seg[rt].r].val);
}

void mfy2(int l,int r,int x,int &rt,ll v){
    if(!rt) rt=++cnt;
    if(l==r) return seg[rt].val=v,void();
    int mid=l+r>>1;
    if(x<=mid) mfy2(l,mid,x,seg[rt].l,v);
    else mfy2(mid+1,r,x,seg[rt].r,v);
    seg[rt].val=__gcd(seg[seg[rt].l].val,seg[seg[rt].r].val);
}

void mfy1(int l,int r,int x,int y,int rt,ll v){
    if(l==r) return mfy2(1,dis.idy,y,p[rt],v),void();
    int mid=l+r>>1;
    if(x<=mid) mfy1(l,mid,x,y,rt<<1,v);
    else mfy1(mid+1,r,x,y,rt<<1|1,v);
    mge(1,dis.idy,p[rt<<1],p[rt<<1|1],p[rt],y);
}

ll que2(int l,int r,int ql,int qr,int rt){
    if(!rt) return 0;
    if(ql<=dis.vy[l]&&dis.vy[r]<=qr) return seg[rt].val;
    int mid=l+r>>1; ll res=0;
    if(ql<=dis.vy[mid]) res=que2(l,mid,ql,qr,seg[rt].l);
    if(qr>dis.vy[mid])  res=__gcd(res,que2(mid+1,r,ql,qr,seg[rt].r));
    return res;   
}

ll que(int l,int r,int ql,int qr,int xl,int xr,int rt){
    if(ql<=l&&r<=qr) return que2(1,dis.idy,xl,xr,p[rt]);
    int mid=l+r>>1; ll res=0;
    if(ql<=mid) res=que(l,mid,ql,qr,xl,xr,rt<<1);
    if(qr>mid) res=__gcd(res,que(mid+1,r,ql,qr,xl,xr,rt<<1|1));
    return res;
}

//-----------------------------------------------------------------

int main(){//Rosario
    int x1,x2,y1,y2,opt;
    rd(q),rd(q),rd(q);
    REP(i,q){
        rd(qry[i].opt);
        if(qry[i].opt==1){
            rd(qry[i].x1),rd(qry[i].y1),rdll(qry[i].val);
            dis.addx(qry[i].x1);  dis.addy(qry[i].y1);
        }else{
            rd(qry[i].x1),rd(qry[i].y1),rd(qry[i].x2),rd(qry[i].y2);
            dis.addx(qry[i].x1), dis.addx(qry[i].x2);
        }
    }
    dis.unq();
    REP(i,q){
        if(qry[i].opt==1) mfy1(1,dis.idx,dis.getx(qry[i].x1),dis.gety(qry[i].y1),1,qry[i].val);
        else printf("%lld\n",que(1,dis.idx,dis.getx(qry[i].x1),dis.getx(qry[i].x2),qry[i].y1,qry[i].y2,1));
    }
    return 0;
}
