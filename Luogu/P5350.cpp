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

const int mod=1e9+7;
struct odt{
    int l,r;
    mutable ll v;
    bool operator<(const odt &x)const{return l<x.l;}
};
odt a[300005],b[300005];
int n,m;
set<odt> s;
#define IT set<odt>::iterator
IT split(int x){
    IT it=--s.upper_bound(odt{x,0,0});
    if(it->l==x) return it;
    int l=it->l,r=it->r; ll v=it->v;
    s.erase(it);  
    s.insert(odt{l,x-1,v});
    return s.insert(odt{x,r,v}).F;
} 
void assign(int l,int r,ll v){
    IT itr=split(r+1),it=split(l);
    s.erase(it,itr); 
    s.insert(odt{l,r,v});
}
void query_sum(int l,int r){
    IT itr=split(r+1),it=split(l);
    ll res=0;
    for(;it!=itr;++it) res=(res+((it->r-it->l+1)*it->v)%mod)%mod;
    cout<<res<<"\n";
}
void add(int l,int r,ll val){
    IT itr=split(r+1),it=split(l);
    for(;it!=itr;++it) it->v=(it->v+val)%mod;
}
void _copy(int l,int r,int l2,int r2){
    int d=abs(l-l2),idx=0;
    IT itr=split(r+1),it=split(l);
    for(;it!=itr;++it) a[++idx]=odt{it->l,it->r,it->v};
    itr=split(r2+1),it=split(l2);  s.erase(it,itr);
    REP1(i,1,idx)
        if(l<l2) s.insert(odt{a[i].l+d,a[i].r+d,a[i].v});
        else s.insert(odt{a[i].l-d,a[i].r-d,a[i].v});
}
void _swap(int l,int r,int l2,int r2){
    if(l>l2) swap(l,l2),swap(r,r2);
    int idx=0,idx2=0,d=l2-l;
    IT itr=split(r+1),it=split(l);
    for(IT itl=it;itl!=itr;++itl) a[++idx]=odt{itl->l,itl->r,itl->v};
    s.erase(it,itr);
    itr=split(r2+1),it=split(l2);
    for(IT itl=it;itl!=itr;++itl) b[++idx2]=odt{itl->l,itl->r,itl->v};
    s.erase(it,itr);
    REP1(i,1,idx) s.insert(odt{a[i].l+d,a[i].r+d,a[i].v});
    REP1(i,1,idx2) s.insert(odt{b[i].l-d,b[i].r-d,b[i].v});
}
void _flip(int l,int r){
    IT itr=split(r+1),it=split(l);
    int idx=0;
    for(IT itl=it;itl!=itr;++itl) a[++idx]=odt{itl->l,itl->r,itl->v};
    s.erase(it,itr);
    REP1(i,1,idx) s.insert(odt{r-a[i].r+l,r-a[i].l+l,a[i].v});
}
void print(){
    for(IT it=s.begin();it!=s.end();++it){
        for(int i=it->l;i<=it->r;++i) cout<<it->v<<' ';
    }cout<<"\n";
}
int main(){Rosario
    cin>>n>>m;
    ll x,l,r,l2,r2,val;
    REP1(i,1,n) cin>>x,s.insert(odt{i,i,x});
    //print();
    while(m--){
        cin>>x>>l>>r;
        if(x==1) query_sum(l,r);
        else if(x==2) cin>>val,assign(l,r,val);
        else if(x==3) cin>>val,add(l,r,val);
        else if(x==4) cin>>l2>>r2,_copy(l,r,l2,r2);
        else if(x==5) cin>>l2>>r2,_swap(l,r,l2,r2);
        else _flip(l,r);
        //print();
    }
    print();
    return 0;
}
