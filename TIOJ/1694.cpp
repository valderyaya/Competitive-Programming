#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
#define lb(x) (x&-x)

inline int read() {
    int ret=0,f=1;char ch=getchar_unlocked();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
    while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
    return ret*f;
}
struct qq{int id,l,r,sl;
    bool operator<(const qq &a)const{
        return sl==a.sl?r<a.r:sl<a.sl;
    }
}v[200005];
int n,m,sqr,bi[23005],sum=0,a[23005],ans[200005];
int get(int x){
    int re=0;
    for(;x;x-=lb(x)) re+=bi[x];
    return re;
}
void add(int x,bool c){
    if(c) sum+=get(n)-get(x);
    else sum+=get(x-1);
    for(;x<=n;x+=lb(x)) bi[x]++;
}
void sub(int x,bool c){
    if(c) sum-=get(n)-get(x);
    else sum-=get(x-1);
    for(;x<=n;x+=lb(x)) bi[x]--;
}
inline void solve(){
    for(int i=a[1];i<=n;i+=lb(i)) bi[i]++;
    for(int i=0,l=1,r=1;i<m;i++){
        while(l<v[i].l) sub(a[l++],0);
        while(l>v[i].l) add(a[--l],0);
        while(r<v[i].r) add(a[++r],1);
        while(r>v[i].r) sub(a[r--],1);
        ans[v[i].id]=sum;
    }
}
int main(){//Rosario
    n=read(),m=read();sqr=sqrt(n)+1;
    REP1(i,1,n) a[i]=read();
    REP(i,m) v[i].l=read(),v[i].r=read(),v[i].id=i,v[i].sl=v[i].l/sqr;
    sort(v,v+m);solve();
    REP(i,m) printf("%d\n",ans[i]);
//    system("pause");
    return 0;
}
