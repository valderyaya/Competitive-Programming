//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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
//#define lb(x) (x&-x)

inline void rd(int &x){
    x=0;char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar_unlocked();
}
void write(int x){
    if(!x) return;
    write(x/10);
    putchar_unlocked(x%10+'0');
}
const int z=5e5+50;
int n,m,cnt=1,s,st[z<<1][20],fst[z],dep[z];
vector<int> v[z];
void dfs(int x,int d){
    st[cnt][0]=dep[x]=d;
    if(!fst[x]) fst[x]=cnt;
    cnt++;
    for(auto &i:v[x]){
        if(fst[i]) continue;
        dfs(i,d+1);
        st[cnt++][0]=d;
    }
}
void build(){
    for(int j=1;(1<<j)<cnt;j++)
        for(int i=1;i+(1<<j)-1<cnt;i++)
            st[i][j]= min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int x,int y){
    if(x>y) x^=y^=x^=y;
    int lg=__lg(y-x+1);
    return min(st[x][lg],st[y-(1<<lg)+1][lg]);
}
int main(){//Rosario
    rd(n),rd(m);
    int a,b,c;
    REP(i,n-1) rd(a),rd(b),v[a].em(b),v[b].em(a);
    dfs(0,1); build();
    while(m--){
        rd(a),rd(b),c=query(fst[a],fst[b]);
        c=dep[a]+dep[b]-c-c;
        if(c) write(c),putchar_unlocked('\n');
        else puts("0");
    }
}
