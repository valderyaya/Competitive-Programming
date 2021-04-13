#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<stdio.h>
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define lb(x) (x&-x)

void rd(int &x){
    x=0;register char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar_unlocked();
}
const int z=1e6+5;
struct edge{int to,nxt;}e[z];
int in[z],cnt,out[z],bit[z],dfn,n,m,val[z],h[z];
void addd(register int u,register int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void add(int x,int v){
    for(;x<=n;x+=lb(x)) bit[x]+=v;
}
int que(int x){
    register int res=0;
    for(;x;x-=lb(x)) res+=bit[x];
    return res;
}
void dfs(int x){
    in[x]=++dfn;
    for(register int i=h[x];i;i=e[i].nxt) dfs(e[i].to);
    out[x]=dfn;
}
void write(int x){
    if(!x) return;
    write(x/10);
    putchar_unlocked(x%10+48);
}
int main(){//Rosario
    rd(n),rd(m);
    register int x,y,k;
    REP(i,n-1) rd(x),rd(y),rd(k),addd(x,y),val[y]=k;
    dfs(0);
    REP1(i,1,n-1) add(in[i],val[i]);
    while(m--){
        rd(k),rd(x);
        if(k==1){
            y=2*(que(out[x])-que(in[x]));
            if(y) write(y),putchar_unlocked('\n');
            else puts("0");
        }else{
            rd(y);
            add(in[x],-val[x]);
            add(in[x],val[x]=y);
        }
    }
    return 0;
}
