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

const int z=5e5+5;
struct qq{
    int l,r;
    bool operator<(const qq &x)const{return l<x.l;}
};
struct pp{
    int v,id;
    bool operator<(const pp &x)const{return v==x.v?id<x.id:v<x.v;}
}que[z],a[z];
multiset<qq> s;
int m,n,ans[z],mx=0,idx=1;
void add(pp x){
    if(s.empty()) {return s.insert(qq{x.id,x.id}),mx=1,void();}
    auto it=s.upper_bound(qq{x.id,0});
    if(it==s.end()){
        auto p=prev(it);
        if(p->r+1==x.id){
            s.insert(qq{p->l,x.id});
            mx=max(mx,x.id-p->l+1);
            s.erase(p);
        }else s.insert(qq{x.id,x.id});
    }else if(it==s.begin()){
        if(x.id+1==it->l){
            mx=max(mx,it->r-x.id+1);
            s.insert(qq{x.id,it->r});
            s.erase(it);
        }else s.insert(qq{x.id,x.id});
    }else{
        auto p=prev(it);
        if(p->r+1==x.id&&x.id+1==it->l){
            mx=max(mx,it->r-p->l+1);
            s.insert(qq{p->l,it->r});
            s.erase(p); s.erase(it);
        }else if(p->r+1==x.id){
            mx=max(mx,x.id-p->l+1);
            s.insert(qq{p->l,x.id});
            s.erase(p);
        }else if(x.id+1==it->l){
            mx=max(mx,it->r-x.id+1);
            s.insert(qq{x.id,it->r});
            s.erase(it);
        }else s.insert(qq{x.id,x.id});
    }
}
int main(){Rosario
    cin>>n; int x;
    REP1(i,1,n) cin>>a[i].v,a[i].id=i;
    cin>>m;
    REP1(i,1,m) cin>>que[i].v,que[i].id=i;
    sort(a+1,a+1+n);
    sort(que+1,que+1+m); 
    //REP1(i,1,n) cout<<a[i].v<<" \n"[i==n];
    // REP1(i,1,m) cout<<que[i].v<<" \n"[i==m];
    for(int i=1,j;i<=n;){
        add(a[i]);
        for(j=i+1;j<=n&&a[j].v==a[i].v;++j) add(a[j]);
        while(que[idx].v<=mx&&idx<=m) ans[que[idx++].id]=a[i].v;
        i=j;
    }
    REP1(i,1,m) cout<<ans[i]<<'\n';
    return 0;
}
