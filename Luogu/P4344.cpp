#include<bits/stdc++.h>
using namespace std;
#define ls rt<<1
#define rs rt<<1|1 

const int z=200005;
struct tree{
    int len,laz,sum,lm,rm,ans;
}seg[z<<2];
int n,m;
void up(int rt){//合并区间
    seg[rt].sum=seg[ls].sum+seg[rs].sum;
    if(seg[ls].lm==seg[ls].len) seg[rt].lm=seg[ls].len+seg[rs].lm;
    else seg[rt].lm=seg[ls].lm;
    if(seg[rs].rm==seg[rs].len) seg[rt].rm=seg[rs].len+seg[ls].rm;
    else seg[rt].rm=seg[rs].rm;
    seg[rt].ans=max(seg[ls].rm+seg[rs].lm,max(seg[ls].ans,seg[rs].ans));
}
void down1(int rt){
    seg[rt].ans=seg[rt].lm=seg[rt].rm=seg[rt].len;
    seg[rt].sum=0;
    seg[rt].laz=1;
}
void down2(int rt){
    seg[rt].ans=seg[rt].lm=seg[rt].rm=0;
    seg[rt].sum=seg[rt].len;
    seg[rt].laz=2;
}
void down(int rt){
    if(seg[rt].laz==1) down1(ls),down1(rs);
    if(seg[rt].laz==2) down2(ls),down2(rs);
    seg[rt].laz=0;
}
void build(int l,int r,int rt){//建树
    seg[rt].len=r-l+1;
    if(l==r) return seg[rt].sum=1,void();
    int mid=l+r>>1;
    build(l,mid,ls),build(mid+1,r,rs);
    up(rt);
}
void modify(int l,int r,int ql,int qr,int rt,int v){//区间修改 v=1代表赋值为0，v=2赋值为1
    if(ql<=l&&r<=qr){
        if(v==1) down1(rt);
        else down2(rt); 
        return;
    }
    down(rt);
    int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,ls,v);
    if(qr>mid) modify(mid+1,r,ql,qr,rs,v);
    up(rt);
}
int que1(int l,int r,int ql,int qr,int rt){//询问1的个数
    if(ql<=l&&r<=qr) return seg[rt].sum;
    down(rt);
    int mid=l+r>>1,sum=0;
    if(ql<=mid) sum=que1(l,mid,ql,qr,ls);
    if(qr>mid) sum+=que1(mid+1,r,ql,qr,rs);
    return sum;
}
int que0(int l,int r,int ql,int qr,int rt){//询问0的个数
    if(ql<=l&&r<=qr) return seg[rt].len-seg[rt].sum;
    down(rt); int mid=l+r>>1,sum=0;
    if(ql<=mid) sum=que0(l,mid,ql,qr,ls);
    if(qr>mid) sum+=que0(mid+1,r,ql,qr,rs);
    return sum;
}
int que2(int l,int r,int ql,int qr,int rt){//询问最大连续0
    if(ql<=l&&r<=qr) return seg[rt].ans;
    down(rt);
    int mid=l+r>>1;
    if(qr<=mid) return que2(l,mid,ql,qr,ls);
    else if(ql>mid) return que2(mid+1,r,ql,qr,rs);
    return max(max(que2(l,mid,ql,qr,ls),que2(mid+1,r,ql,qr,rs)),min(seg[ls].rm,mid-ql+1)+min(seg[rs].lm,qr-mid));
    //这段需要想一下，意思等同于max({左子树答案，右子树答案，左子树的合法rmax+右子树的合法lmax}),合法是指说在区间ql~qr内
}
void assign(int l,int r,int ql,int qr){//二分搜
    int mid, sum=que1(1,n,l,r,1), L=ql, R=qr+1;
    if(sum==0) return;
    modify(1,n,l,r,1,1);
    while(L+1<R){
        mid=L+R>>1;
        if(sum>=que0(1,n,ql,mid,1)) L=mid;
        else R=mid;
    }
    modify(1,n,ql,L,1,2);
}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    build(1,n,1);
    int k,l,r,L,R;
    while(m--){
        cin>>k>>l>>r;
        if(!k) modify(1,n,l,r,1,1);
        else if(k==1) cin>>L>>R,assign(l,r,L,R);
        else cout<<que2(1,n,l,r,1)<<"\n";
    }
    return 0;
}
