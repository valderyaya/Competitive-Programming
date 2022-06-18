//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,intt>
#define pll pair<ll,ll>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct node{
    int key,pri,sz;
    node *l,*r;
    node(int k){key=k,pri=rand(),sz=1,l=r=0;}
    void up(){
        sz=1;
        if(l) sz+=l->sz;
        if(r) sz+=r->sz;
    }
}*rt=nullptr;
inline int siz(node *p){return p?p->sz:0;}
node *merge(node *a,node *b){
    if(!a||!b) return a?a:b;
    if(a->pri<b->pri){
        a->r=merge(a->r,b);
        a->up();return a;
    }else{
        b->l=merge(a,b->l);
        b->up();return b;
    }
}
void split(node *p,node *&a,node *&b,int k){
    if(!p) return a=b=nullptr,void();
    if(p->key<k){
        a=p;split(p->r,a->r,b,k);
    }else{
        b=p;split(p->l,a,b->l,k);
    }
    p->up();
}
void inst(node *&p,int k){
    node *a,*b;
    split(p,a,b,k);
    p=merge(a,merge(new node(k),b));
}
int kth(node *p,int k){
    if(k==siz(p->l)+1) return p->key;
    if(k<=siz(p->l)) return kth(p->l,k);
    return kth(p->r,k-siz(p->l)-1);
}
int a[200005],b[200005],n,m,c=1,now=0;
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i];
    REP1(i,1,m) cin>>b[i];
    REP1(i,1,n){
        if(i==1) rt=new node(a[i]);
        else inst(rt,a[i]);
        while(b[c]==i) cout<<kth(rt,c++)<<"\n";
    }
//    system("pause");
    return 0;
}
