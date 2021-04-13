#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

inline int maxx(int a,int b){return a>b?a:b;}
inline int read(){
    int x=0;char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar_unlocked();
    return x;
}
void write(int x){
    if(!x) return;
    write(x/10);
    putchar_unlocked(x%10+48);
}
const int z=1001;
int bit[z][z],n;
pii a[z*z];
void modify(int x,int y,int v){
    for(;x<=n;x+=lb(x))
        for(int i=y;i<=n;i+=lb(i))
            bit[x][i]=maxx(bit[x][i],v);
}
int query(int x,int y){
    int res=0;
    for(;x;x-=lb(x))
        for(int i=y;i;i-=lb(i))
            res=maxx(res,bit[x][i]);
    return res;
}
int main(){//Rosario
    n=read();
    int x,y;
    REP1(i,1,n) REP1(j,1,n) a[read()]=mkp(i,j);
    REP1(i,1,n*n) if(a[i].F) modify(a[i].F,a[i].S,query(a[i].F,a[i].S)+1);
    write(query(n,n));
    return 0;
}
