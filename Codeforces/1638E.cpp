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
#define lb(x) x&-x
#define em emplace_back

#define int ll
const int z=1e6+1;
ll n,m,col[z<<1],tag[z],seg[z<<1],laz[z<<1],claz[z<<1];
#define rt(l,r) l+r|l!=r
bitset<z<<1> same;
void up(int l,int r){
    int mid=l+r>>1,p=rt(l,r), ls=rt(l,mid) ,rs=rt(mid+1,r);
    col[p]=col[ls];
    same[p]= (col[ls]==col[rs])&&(same[ls]&&same[rs]);
}
void build(int l,int r){
    same[rt(l,r)]=1,col[rt(l,r)]=claz[rt(l,r)]=1;
    if(l==r) return;
    int mid=l+r>>1;
    build(l,mid); build(mid+1,r);
}
void down(int l,int r){
    int p=rt(l,r);
    if(!laz[p]&&claz[p]==1) return;
    int mid=l+r>>1, ls=rt(l,mid), rs=rt(mid+1,r);
    col[ls]=claz[p], col[rs]=claz[p], claz[ls]=claz[p], claz[rs]=claz[p];
    laz[ls]+=laz[p], laz[rs]+=laz[p], seg[ls]+=laz[p], seg[rs]+=laz[p];
    laz[p]=0,claz[p]=1;
}
void mdf(int l,int r,int ql,int qr,int cl){
    if(ql<=l&&r<=qr&&same[rt(l,r)]){
        int p=rt(l,r);
        laz[p]+=tag[col[p]]-tag[cl], seg[p]+=tag[col[p]]-tag[cl];
        claz[p]=col[p]=cl; return;  
    }down(l,r);
    int mid=l+r>>1;
    if(ql<=mid) mdf(l,mid,ql,qr,cl);
    if(qr>mid) mdf(mid+1,r,ql,qr,cl);
    up(l,r);
}
ll qry(int l,int r,int x){
    if(l==r) return tag[col[rt(l,r)]]+seg[rt(l,r)];
    down(l,r);
    int mid=l+r>>1;
    if(x<=mid) return qry(l,mid,x);
    return qry(mid+1,r,x);
}
// void print(int l,int r){
//     if(l==r) return cout<<tag[col[rt(l,r)]]+seg[rt(l,r)]<<' ',void();
//     down(l,r);
//     int mid=l+r>>1;
//     print(l,mid); print(mid+1,r);
// }
signed main(){Rosario
    cin>>n>>m;
    build(1,n);
    string s;
    for(int x,y,c;m--;){
        cin>>s>>x;
        if(s[0]=='C'){
            cin>>y>>c;
            mdf(1,n,x,y,c);
        }else if(s[0]=='A'){
            cin>>y;
            tag[x]+=y;
        }else if(s[0]=='Q'){
            cout<<qry(1,n,x)<<"\n";
        }
        //print(1,n);cout<<endl;
    }
    return 0;
}
