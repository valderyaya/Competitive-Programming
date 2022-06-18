#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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
    int ret=0;char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') ret=(ret<<3)+(ret<<1)+(c^48),c=getchar_unlocked();
    return ret;
}
const int maxn=100005;
struct edge{
    int nxt,to,w;
}v[maxn<<1]={};
int n,k,dis[maxn],st,ed,max_=0,ans=0,to[maxn],h[maxn],cnt=0;
bitset<maxn> is;
bool ck=0;
inline void add(int x,int y){
    v[++cnt].to=y;
    v[cnt].w=1;
    v[cnt].nxt=h[x];
    h[x]=cnt;
}
void dfs(int x,int p,int d){
    if(d>max_) max_=d,ed=x;
    for(int i=h[x];i;i=v[i].nxt)
        if(v[i].to!=p) dfs(v[i].to,x,d+1);
}
void dp(int x,int p){
    for(int i=h[x];i;i=v[i].nxt){
        if(v[i].to==p) continue;
        dp(v[i].to,x);
        ans=max(ans,dis[x]+dis[v[i].to]+v[i].w);
        dis[x]=max(dis[x],dis[v[i].to]+v[i].w);
    }
}
void dfs_find(int x,int p,int tar){
    if(ck) return;
    for(int i=h[x];i;i=v[i].nxt){
        if(v[i].to==p) continue;
        if(v[i].to==tar){
            to[x]=v[i].to;ck=1;
            return ;
        }
        to[x]=v[i].to;
        dfs_find(v[i].to,x,tar);
        if(ck) return;
    }
}
int main(){//Rosario
    n=read(),k=read();
    for(int a,b,i=0;i<n-1;++i) a=read(),b=read(),add(a,b),add(b,a);
    dfs(1,0,0);max_=0;st=ed;dfs(st,0,0);
    if(k==1){
        printf("%d\n",2*(n-1)-max_+1);
        return 0;
    }
    dfs_find(st,0,ed);
    for(int i=st;i;i=to[i]) is[i]=1;
    REP1(i,1,n)
        if(is[i])
            for(int j=h[i];j;j=v[j].nxt) if(is[v[j].to]) v[j].w=-1;
    dp(1,0);
    printf("%d\n",2*n-max_-ans);
//    system("pause");
    return 0;
}
