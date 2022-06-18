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
#define IT set<node>::iterator

int n,m;
struct node{
    int l,r;
    mutable char c;
    node(int il,int ir=-1,char ic='0'):l(il),r(ir),c(ic){};
    bool operator<(const node &x)const{return l<x.l;}
};
set<node> s;
IT split(int x){
    IT it=--s.upper_bound(node(x));
    if(it->l==x) return it;
    int l=it->l,r=it->r;char v=it->c;
    s.erase(it); s.insert(node(l,x-1,v));
    return s.insert(node(x,r,v)).F;
}
void assign(int l,int r,int x){
    IT itr=split(r+1),it=split(l);
    s.erase(it,itr); s.insert(node(l,r,x));
}
bool que(int l,int r){
    IT itr=split(r+1),itl=split(l);
    char c=itl->c;
    for(IT it=itl;it!=itr;it++) if(it->c!=c) return 0;
    if(l==1||r==n) return 1;
    --itl;
    return itl->c!=itr->c;
}
string str;
int main(){Rosario
    cin>>n>>str>>m;
    REP(i,str.size()) s.insert(node(i+1,i+1,str[i]));
    char c,d;int l,r;
    while(m--){
        cin>>c>>l>>r;
        if(c=='A') cin>>d,assign(l,r,d);
        else cout<<(que(l,r)?"Yes":"No")<<"\n";
    }
//    system("pause");
    return 0;
}
