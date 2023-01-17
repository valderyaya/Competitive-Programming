//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
const int z=2e5+5;
int n,q,pri[z],val[z],a[z],cnt,ch[2][z],sz[z],rt,tra[z],idx;
int node(int x){
    int ret=(idx?tra[idx--]:++cnt);
    val[ret]=x;
    sz[ret]=1;
    pri[ret]=rand();
    ch[0][ret]=ch[1][ret]=0;
    return ret;
}
void up(int p){sz[p]=1+sz[ch[0][p]]+sz[ch[1][p]];}
int merge(int x,int y){
    if(!x||!y) return x|y;
    if(pri[x]<pri[y]){
        ch[1][x]=merge(ch[1][x],y);
        up(x); return x;
    }else{
        ch[0][y]=merge(x,ch[0][y]);
        up(y); return y;
    }
}
void split(int p,int &x,int &y,int k){
    if(!p) return x=y=0,void();
    if(val[p]<k){
        x=p;
        split(ch[1][p],ch[1][x],y,k);
    }else{
        y=p;
        split(ch[0][p],x,ch[0][y],k);
    }
    up(p);
}
void erase(int k){
    int x=0,y=0,o=0;
    split(rt,x,y,k);
    split(y,y,o,k+1);
    tra[++idx]=y;
    y=merge(ch[0][y],ch[1][y]);
    rt=merge(x,merge(y,o));
}
void insert(int k){
    int x=0,y=0;
    split(rt,x,y,k);
    rt=merge(x,merge(node(k),y));
}
int qry(int l,int r){
    int x=0,y=0,o=0,ret;
    split(rt,x,y,l);
    split(y,y,o,r+1);
    ret=sz[y];
    rt=merge(x,merge(y,o));
    return ret;
}
void rd(int &x){
    x=0;register char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar_unlocked();
}
void write(int x){
    if(!x) return;
    write(x/10);
    putchar_unlocked(48+x%10);
}
void print(int x){
    if(!x) puts("0");
    else{
        write(x);puts("");
    }
}
signed main(){Aincrad
    srand(time(0));
    rd(n),rd(q);
    REP1(i,1,n) rd(a[i]),insert(a[i]);
    char c;
    for(int x,y;q--;){
        c=getchar_unlocked();
        rd(x);rd(y);
        if(c=='!'){
            erase(a[x]);
            insert(a[x]=y);
        }else print(qry(x,y));
    }
    return 0;
}
