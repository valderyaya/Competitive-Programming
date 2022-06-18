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

inline int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
int n,m,bel[1000005],a[1000005],s[1000005],len,tot,st[1005],ed[1005],tag[1005]={};
void init(){
    n=read(),m=read();//cin>>n>>m;
    len=sqrt(n);
    tot=n/len+!!(n%len);
    REP1(i,1,n) a[i]=read(),s[i]=a[i],bel[i]=(i-1)/len+1;
    REP1(i,1,tot) st[i]=(i-1)*len+1,ed[i]=len*i;
    ed[tot]=n;
    REP1(i,1,tot) sort(s+st[i],s+ed[i]+1);
}
void sort_(int x){
    REP1(i,st[x],ed[x]) s[i]=a[i];
    sort(s+st[x],s+ed[x]+1);
}
void modify(int l,int r,int c){
    int x=bel[l],y=bel[r];
    if(x==y){
        REP1(i,l,r) a[i]+=c;
        sort_(x);return;
    }
    REP1(i,l,ed[x]) a[i]+=c;
    REP1(i,st[y],r) a[i]+=c;
    for(int i=x+1;i<y;i++) tag[i]+=c;
    sort_(x); sort_(y);
}
int query(int l,int r,int c){
    int res=0,x=bel[l],y=bel[r];
    if(x==y){
        REP1(i,l,r) if(a[i]+tag[x]>=c) res++;
        return res;
    }
    REP1(i,l,ed[x]) if(a[i]+tag[x]>=c) res++;
    REP1(i,st[y],r) if(a[i]+tag[y]>=c) res++;
    for(int i=x+1;i<y;i++) res+=ed[i]-(lower_bound(s+st[i],s+ed[i]+1,c-tag[i])-s)+1;
    return res;
}
int main(){//Rosario
    init();
    char c;
    int l,r,x;
    while(m--){
        cin>>c>>l>>r>>x;
        if(c=='A') printf("%d\n",query(l,r,x));
        else modify(l,r,x);
    }
//    system("pause");
    return 0;
}
