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

inline int read()
{
	int re=0,k=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')k=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){re=re*10+ch-48;ch=getchar();}
	return re*k;
}
struct qq{int ls,rs,pri,val,sz;}q[1100005];
int rt=0,tot=0,ans=0,last=0,n,m;
inline void up(int x){q[x].sz=q[q[x].ls].sz+q[q[x].rs].sz+1;}
int merge(int a,int b){
    if(!a||!b) return a|b;
    if(q[a].pri<q[b].pri){
        q[a].rs=merge(q[a].rs,b);
        up(a); return a;
    }else{
        q[b].ls=merge(a,q[b].ls);
        up(b); return b;
    }
}
void split(int x,int &a,int &b,int k){
    if(!x) return a=b=0,void();
    if(q[x].val<=k)
        a=x,split(q[x].rs,q[a].rs,b,k);
    else 
        b=x,split(q[x].ls,a,q[b].ls,k);
    up(x);
}
int node(int k){
    q[++tot]=qq{0,0,rand(),k,1};
    return tot;
}
void insert(int x){
    int a,b;
    split(rt,a,b,x);
    rt=merge(merge(a,node(x)),b);
}
void erase(int k){
    int a,b,c;
    split(rt,a,c,k);
    split(a,a,b,k-1);
    b=merge(q[b].ls,q[b].rs);
    rt=merge(merge(a,b),c);
}
int kth(int x,int k){
    while(1){
        if(k==q[q[x].ls].sz+1) return q[x].val;
        if(k<=q[q[x].ls].sz) x=q[x].ls;
        else k-=q[q[x].ls].sz+1,x=q[x].rs;
    }
}
int fin(int k){
    int a,b,re;
    split(rt,a,b,k-1);
    re=q[a].sz+1;
    rt=merge(a,b);
    return re;
}
int pre(int k){
    int a,b,re;
    split(rt,a,b,k-1);
    re=kth(a,q[a].sz);
    rt=merge(a,b);
    return re;
}
int nxt(int k){
    int a,b,re;
    split(rt,a,b,k);
    re=kth(b,1);
    rt=merge(a,b);
    return re;
}
int main(){//Rosario
    srand(19260811);
    n=read(),m=read();//cin>>n>>m;
    int k,x;
    while(n--) x=read(),insert(x);
    while(m--){
        k=read(),x=read();x^=last;
        if(k==1) insert(x);
        else if(k==2) erase(x);
        else if(k==3) ans^=last=fin(x);
        else if(k==4) ans^=last=kth(rt,x);
        else if(k==5) ans^=last=pre(x);
        else ans^=last=nxt(x);
    }printf("%d\n",ans);//cout<<ans<<"\n";
//    system("pause");
    return 0;
}
