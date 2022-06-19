#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

#define int ll

const int z=5e5+5;
int n,q,seg[z<<2],laz[z<<2];
#define ls rt<<1
#define rs rt<<1|1

void up(int rt){
    seg[rt]=seg[ls]+seg[rs];
}

void down(int rt,int l,int r){
    if(!~laz[rt]) return;
    laz[ls]=laz[rs]=laz[rt];
    int mid=l+r>>1;
    seg[ls]=(mid-l+1)*laz[rt];
    seg[rs]=(r-mid)*laz[rt];
    laz[rt]=-1;
}

void mdf(int l,int r,int ql,int qr,int rt,int v){
    if(ql<=l&&r<=qr){
        seg[rt]=(r-l+1)*v;
        laz[rt]=v;
        return;
    }
    down(rt,l,r);
    int mid=l+r>>1;
    if(ql<=mid) mdf(l,mid,ql,qr,ls,v);
    if(qr>mid) mdf(mid+1,r,ql,qr,rs,v);
    up(rt);
}

int qry(int l,int r,int ql,int qr,int rt){
    if(ql<=l&&r<=qr) return seg[rt];
    down(rt,l,r);
    int mid=l+r>>1, res=0;
    if(ql<=mid) res=qry(l,mid,ql,qr,ls);
    if(qr>mid) res+=qry(mid+1,r,ql,qr,rs);
    return res;
}

struct node{
    mutable int l,r,v;
    node(int l_, int r_=-1, int v_=0):l(l_), r(r_), v(v_){}
    bool operator<(const node &x)const{
        return l<x.l;
    }
};
set<node> odt;

auto split(int x){
    auto it=--odt.upper_bound(node(x));
    if(it->l==x) return it;
    int l=it->l, r=it->r, v=it->v;
    if(r<x) return odt.insert(node(x,x,0)).F;
    odt.erase(it);
    odt.insert(node(l,x-1,v));
    return odt.insert(node(x,r,v)).F;
}

void assign(int l,int r,int x){
    auto itr=split(r+1), it=split(l);
    odt.erase(it,itr);
    mdf(1,n,l,r,1,x);
    odt.insert(node(l,r,x));
}

void divi(int l,int r,int x){
    auto itr=split(r+1), it=split(l);
    while(it!=itr){
        it->v/=x;
        mdf(1,n,it->l,it->r,1,it->v);
        if(it->v==0) it=odt.erase(it);
        else it=next(it);
    }
}

signed main(){valder
    memset(laz,-1,sizeof(laz));
    odt.insert(node(0,n+1));
    cin>>n>>q;
    for(int i=1,x;i<=n;++i){
        cin>>x;
        assign(i,i,x);
    }
    for(int l,r,x,k;q--;){
        cin>>k>>l>>r;
        if(k!=3) cin>>x;
        if(k==1)
            divi(l,r,x);
        else if(k==2)
            assign(l,r,x);
        else
            cout<<qry(1,n,l,r,1)<<endl;
    }
}
