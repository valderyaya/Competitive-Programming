#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

#define IT set<chtholly>::iterator
struct chtholly{
    int l,r;
    mutable int v;
    chtholly(int il,int ir=-1,int iv=0):l(il),r(ir),v(iv){};
    bool operator<(const chtholly &x)const{return l<x.l;}
};
set<chtholly> odt;
int n;
IT split(int x){
    IT it=--odt.upper_bound(chtholly(x));
    if(it->l==x) return it;
    int l=it->l,r=it->r,v=it->v;
    odt.erase(it);
    odt.insert(chtholly(l,x-1,v));
    return odt.insert(chtholly(x,r,v)).F;
}
void assign(int l,int r,int v){
    IT itr=split(r+1),it=split(l);
    odt.erase(it,itr);
    odt.insert(chtholly(l,r,v));
}
int query(int l,int r,int x){
    IT itr=split(r+1),it=split(l);
    int mx=0,sum=0;
    for(;it!=itr;it++)
        if(it->v==x) sum+= it->r-it->l+1;
        else mx=max(mx,sum),sum=0;
    return mx;
}
int main(){Rosario
    cin>>n;    
    int l,r,L=1e7,R=0;
    odt.insert(chtholly(0,1000000));
    REP(i,n) cin>>l>>r,assign(l,r-1,1),L=min(L,l),R=max(R,r);
    cout<<query(L,R,1)<<' '<<query(L,R,0)<<"\n";
//    wait
    return 0;
}
