//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define lb(x) (x&-x)

inline void rd(int &x){
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
const int z=1e5+5,zz=5e5+5,zzz=zz<<6;
int a[z],cnt=0,idx=0,n,q[z],m,lc[zzz],rc[zzz],val[zzz],pri[zzz],rt[zz];
long long unsigned int bit[z];
void add(int x,int v){for(;x<=n;x+=lb(x)) bit[x]+=v;}
long long unsigned int que(int x){
    long long unsigned int sum=0;
    for(;x;x-=lb(x)) sum+=bit[x];
    return sum;
}
int node(int x){
    val[++cnt]=x;
    lc[cnt]=rc[cnt]=0;
    pri[cnt]=rand();
    return cnt;
}
int merge(int x,int y){
    if(!x||!y) return x|y;
    if(pri[x]<pri[y]){
        rc[x]=merge(rc[x],y);
        return x;
    }lc[y]=merge(x,lc[y]);
    return y;
}
void split(int p,int &x,int &y,int k){
    if(!p) return x=y=0,void();
    if(val[p]<=k) x=p,split(rc[p],rc[x],y,k);
    else y=p,split(lc[p],x,lc[y],k);
}
void dfs(int x,int v){
    if(!x) return;
    dfs(lc[x],v);
    if(a[val[x]]%v==0) add(val[x],-a[val[x]]),a[val[x]]/=v,add(val[x],a[val[x]]);
    if(a[val[x]]%v==0) q[++idx]=val[x];
    dfs(rc[x],v);
}
void del(int p,int l,int r){
    if(p==1) return;
    int x,y,z,o=0; idx=0;
    split(rt[p],x,y,l-1);
    split(y,y,z,r);
    dfs(y,p);
    REP1(i,1,idx) o=merge(o,node(q[i]));
    rt[p]=merge(x,merge(o,z));
}
vector<int> f[zz];
void write(long long unsigned int x){
    if(!x) return;
    write(x/10);
    putchar(x%10+'0');
}
int main(){//Rosario
    srand(time(0));
    rd(n);rd(m);
    REP1(i,1,n) {rd(a[i]),add(i,a[i]);
        for(int j=1;j*j<=a[i];++j)
            if(a[i]%j==0){
                f[j].em(i);
                if(j*j!=a[i]) f[a[i]/j].em(i);
            }
    }
    REP1(i,1,500000)
        if(f[i].size()){rt[i]=0;
            for(auto &j:f[i]) rt[i]=merge(rt[i],node(j));
        }
    int l,r,x,k;
    while(m--){
        rd(k),rd(l),rd(r);
        if(k==2) {
            long long unsigned int tmp=que(r)-que(l-1);
            if(!tmp) puts("0");
            else write(tmp),putchar('\n');
        }else rd(x),del(x,l,r);
    }
    return 0;
}
