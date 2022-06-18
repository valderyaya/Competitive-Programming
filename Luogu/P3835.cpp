#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=25000000,inf=2147483647;
struct treap{int ls,rs,val,pri,sz;}tp[z];
int tot=0,n,Rt[500005];
int node(int x){
    tp[++tot]=treap{0,0,x,rand(),1};
    return tot;
}
void up(int x){tp[x].sz=1+tp[tp[x].ls].sz+tp[tp[x].rs].sz;}
// void print(int x){
//     if(!x) return;
//     print(tp[x].ls);
//     cout<<tp[x].val<<' ';
//     print(tp[x].rs);
// }
int merge(int a,int b){
    if(!a||!b) return a|b;
    if(tp[a].pri<tp[b].pri){
        tp[a].rs=merge(tp[a].rs,b);
        up(a); 
        return a;
    }else{
        tp[b].ls=merge(a,tp[b].ls);
        up(b); 
        return b;
    }
}
void split(int &a,int &b,int p,int k){
    if(!p) return a=b=0,void();
    if(tp[p].val<=k){
        a=++tot;
        tp[a]=tp[p];
        split(tp[a].rs,b,tp[p].rs,k);
        up(a);
    }else{
        b=++tot;
        tp[b]=tp[p];
        split(a,tp[b].ls,tp[p].ls,k);
        up(b);
    }
}
void insert(int &rt,int x){
    int a,b;
    split(a,b,rt,x);
    rt=merge(a,merge(node(x),b));
}
void del(int &rt,int x){
    int a,b,c;
    split(a,b,rt,x);
    split(a,c,a,x-1);
    c=merge(tp[c].ls,tp[c].rs);
    rt=merge(a,merge(c,b));
}
int kth(int &rt,int x){
    if(tp[tp[rt].ls].sz+1==x) return rt;
    if(tp[tp[rt].ls].sz>=x) return kth(tp[rt].ls,x);
    return kth(tp[rt].rs,x-tp[tp[rt].ls].sz-1);
}
void rk(int &rt,int x){
    int a,b,c;
    split(a,b,rt,x-1);
    cout<<tp[a].sz+1<<"\n";
    rt=merge(a,b);
}
void pre(int &rt,int x){
    int a,b;
    split(a,b,rt,x-1);
    if(a)cout<<tp[kth(a,tp[a].sz)].val<<"\n";
    else cout<<-inf<<"\n";
    rt=merge(a,b);
}
void nxt(int &rt,int x){
    int a,b;
    split(a,b,rt,x);
    if(b) cout<<tp[kth(b,1)].val<<"\n";
    else cout<<inf<<"\n";
    rt=merge(a,b);
}
int main(){Rosario
    srand(time(0));
    cin>>n;
    int opt,v,x;
    REP1(i,1,n){
        cin>>v>>opt>>x;
        Rt[i]=Rt[v];
        if(opt==1) insert(Rt[i],x);
        else if(opt==2) del(Rt[i],x);
        else if(opt==3) rk(Rt[i],x);
        else if(opt==4) cout<<tp[kth(Rt[i],x)].val<<"\n";
        else if(opt==5) pre(Rt[i],x);
        else nxt(Rt[i],x);
        //print(Rt[i]); cout<<endl;
    }
    return 0;
}
