#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back

#define ls rt<<1
#define rs ls|1
struct segment{
    double m,k;
    double cal(int x){return m*x+k;}
}sg[100005];
const double eps =1e-8;
int n,seg[160000],idx;
void mdf(int l,int r,int ql,int qr,int rt,int id){
    int mid=l+r>>1;
    if(ql<=l&&r<=qr){
        if(sg[seg[rt]].cal(mid)+eps < sg[id].cal(mid)) swap(seg[rt],id);
        if(sg[seg[rt]].cal(l)+eps < sg[id].cal(l)) mdf(l,mid,ql,qr,ls,id);
        if(sg[seg[rt]].cal(r)+eps < sg[id].cal(r)) mdf(mid+1,r,ql,qr,rs,id);
        return;
    }
    if(ql<=mid) mdf(l,mid,ql,qr,ls,id);
    if(qr>mid) mdf(mid+1,r,ql,qr,rs,id);
}
int qry(int l,int r,int rt,int x){
    if(l==r) return seg[rt];
    int ret,mid=l+r>>1;
    if(x<=mid) ret=qry(l,mid,ls,x);
    else ret=qry(mid+1,r,rs,x);
    if(sg[ret].cal(x)>eps+sg[seg[rt]].cal(x)) return ret;
    return seg[rt];
}
const int md=39989,mod=1e9;
signed main(){Rosario
    cin>>n;
    for(int op,last=0,x,y,xx,yy,i=0;i<n;++i){
        cin>>op;
        if(op){
            cin>>x>>y>>xx>>yy;
            x=(x+last-1)%md+1, y=(y+last-1)%mod+1, xx=(xx+last-1)%md+1, yy=(yy+last-1)%mod+1;
            if(x>xx) swap(x,xx),swap(y,yy);
            if(x==xx)
                sg[++idx]={0,max(y,yy)};
            else
                sg[++idx]={(double)(yy-y)/(xx-x),y-(double)(yy-y)/(xx-x)*x};
            mdf(1,md,x,xx,1,idx);
        }else{
            cin>>x;
            x=(x+last-1)%md+1;
            last=qry(1,md,1,x);
            cout<<last<<"\n";
        }
    }
    return 0;
}
