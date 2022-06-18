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


int seg[100000<<2]={},laz[100000<<2]={},n,m;
void down(int l,int r,int rt){
    if(l==r||laz[rt]==0) return;
    laz[rt<<1]^=1,laz[rt<<1|1]^=1;
    seg[rt<<1]^=1,seg[rt<<1|1]^=1;
    laz[rt]=0;
}
void modify(int l,int r,int ql,int qr,int rt){
    down(l,r,rt);
    if(ql<=l&&r<=qr){
        laz[rt]=1;seg[rt]^=1;
        return;
    }int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1);
}
int query(int l,int r,int rt,int x){
    down(l,r,rt);
    if(l==r&&l==x) return seg[rt];
    int mid=l+r>>1;
    if(x<=mid) return query(l,mid,rt<<1,x);
    else return query(mid+1,r,rt<<1|1,x);
}
int main(){Rosario
    cin>>n>>m;
    int k,a,b;
    while(m--){
        cin>>k>>a;
        if(k==1) cin>>b,modify(1,n,a,b,1);
        else cout<<query(1,n,1,a)<<"\n";
    }
//    system("pause");
    return 0;
}
