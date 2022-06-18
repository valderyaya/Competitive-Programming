//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";

#define IT set<node>::iterator
struct node{
    int l,r;
    mutable int v;
    node(int il,int ir=-1,int iv=0):l(il),r(ir),v(iv){};
    bool operator<(const node &x)const{return l<x.l;}
};
set<node> s;
IT split(int x){
    IT it=--s.upper_bound(node(x));
    if(it->l==x) return it;
    int l=it->l,r=it->r,v=it->v;
    s.erase(it); s.insert(node(l,x-1,v));
    return s.insert(node(x,r,v)).F;
}
void assign(int l,int r,int x){
    IT itr=split(r+1),it=split(l);
    s.erase(it,itr); s.insert(node(l,r,x));
}
int que(int l,int r){
    set<int> t;
    IT itr=split(r+1),it=split(l);
    for(;it!=itr;it++)if(it->v) t.insert(it->v);
    return t.size();
}
int n,l,r,m,c=1;
int main(){Rosario
    cin>>n>>m;
    s.insert(node(1,n,0));
    while(m--) cin>>l>>r,assign(l,r,c++);
    cout<<que(1,n)<<"\n";
//    system("pause");
    return 0;
}
