//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

const int z=1e5+5,inf=1e7;
struct qq{
    int ch[2],cnt;
    qq(){ch[0]=ch[1]=0;cnt=-inf;}
    inline int& operator[](int x){return ch[x];}
}tr[25000000];
int n,m,a[z<<2],tot=0;
inline void add(int rt,int x,int day){
    tr[rt].cnt=max(tr[rt].cnt,day);
    for(int i=25;~i;--i){
        int c=x>>i&1;
        if(!tr[rt][c]) tr[rt][c]=++tot;
        rt=tr[rt][c]; tr[rt].cnt=max(tr[rt].cnt,day);
        //cout<<rt<<endl;
    }
}
int get(int rt,int x,int day){
    int res=0;
    for(int i=25;~i;--i){
        int c=x>>i&1;
        if(tr[rt][c^1]&&tr[tr[rt][c^1]].cnt>=day) rt=tr[rt][c^1],res|=(1<<i);
        else rt=tr[rt][c];
    }
    return res;
}
void modify(int l,int r,int x,int val,int day,int rt){
    if(!a[rt]) a[rt]=++tot;
    add(a[rt],val,day);
    if(l==r) return;
    int mid=l+r>>1;
    if(x<=mid) modify(l,mid,x,val,day,rt<<1);
    else modify(mid+1,r,x,val,day,rt<<1|1);
}
int query(int l,int r,int ql,int qr,int val,int day,int rt){
    if(ql<=l&&r<=qr) return get(a[rt],val,day);
    int mid=l+r>>1,res=0;
    if(ql<=mid) res=query(l,mid,ql,qr,val,day,rt<<1);
    if(qr>mid) res=max(res,query(mid+1,r,ql,qr,val,day,rt<<1|1));
    return res;
}
int main(){Rosario
    cin>>n>>m;int l,r,val,day=1,x;
    REP1(i,1,n) cin>>x,modify(1,n,i,x,inf,1);
    while(m--){
        cin>>x;
        if(x){
            cin>>l>>r>>val>>x;
            cout<<query(1,n,l,r,val,max(0,day-x+1),1)<<"\n";
        }else{
            cin>>x>>val;
            modify(1,n,x,val,++day,1);
        }
    }
    return 0;
}
