#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

struct  node{
    int key,pri,sz;
    node *l,*r;
    node(int k){key=k,pri=rand(),sz=1,l=r=0;}
    void up(){
        sz=1;
        if(l) sz+=l->sz;
        if(r) sz+=r->sz;
    }
}*rt;
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
    if(!p){a=b=0;return;};
    if(p->key<k){
        a=p;
        split(p->r,a->r,b,k);
    }else{
        b=p;
        split(p->l,a,b->l,k);
    }p->up();
}
void inst(node *&p,int k){
    node *a,*b;
    split(p,a,b,k);
    p=merge(a,merge(new node(k),b));
}
bool erase(node *&p,int k){
    if(!p) return 0;
    if(p->key==k){
        node *r=p;
        p=merge(p->l,p->r);
        delete r;
        return 1;
    }
    node *r= k< p->key?p->l:p->r;
    if(erase(r,k)) return p->up(),1;
    return 0;
}
int kth(node *p,int k){
    if(k<=siz(p->l)) return kth(p->l,k);
    if(siz(p->l)+1==k) return p->key;
    return kth(p->r,k-siz(p->l)-1);
}
int n,k=1,c=1;
string s;
int main(){Rosario
    srand(time(0));
    while(cin>>s){
        if(s=="PUSH"){cin>>n;
            if(c) c=0,rt=new node(n);
            else inst(rt,n);
        }else if(s=="GET"){
            if(siz(rt)>=k) cout<<kth(rt,k)<<"\n",k++;
        }else if(s=="EXIT"){
            node *t=rt;k=c=1;
            rt=nullptr;
            delete t;
        }else if(s=="END") break;
    }
//    system("pause");
    return 0;
}
