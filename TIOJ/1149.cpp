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
//#define line cout<<"-------------------------\n";

inline int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}
void ip(int &x){
    char c;
    while(c=getchar(),c!='m'&&c!='h');
    x=read();x=(x-1)<<1;
    if(c=='m') x|=1;
}
struct edge{int to,nxt;}e[2500];
int low[405],n,m,t,tim,dfn[405],col[405],cl,h[405],cnt;
bitset<405> in;
stack<int> st;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x){
    low[x]=dfn[x]=++tim;
    in[x]=1;st.emplace(x);
    for(int i=h[x];i;i=e[i].nxt){
        if(!dfn[e[i].to]) dfs(e[i].to),low[x]=min(low[x],low[e[i].to]);
        else if(in[e[i].to]&&dfn[e[i].to]<dfn[x]) low[x]=min(low[x],dfn[e[i].to]);
    }
    if(low[x]==dfn[x]){++cl;
        for(int u=-1;u!=x;st.pop()) u=st.top(),in[u]=0,col[u]=cl;
    }
}

int main(){//Rosario
    cin>>t;
    int a,b;
    while(t--){
        cin>>n>>m;
        n<<=1;cnt=cl=tim=0;
        REP(i,n*2) dfn[i]=h[i]=0;
        while(m--){
            ip(a),ip(b);
            add(a,b+n);
            add(b,a+n);
        }
        REP(i,n) add(i^1,i+n),add(i+n,i^1);
        REP(i,n*2) if(!dfn[i]) dfs(i);
        bool ck=1;
        REP(i,n) if(col[i]==col[i^1]||col[i]==col[i+n]){ck=0;break;}
        cout<<(ck?"GOOD":"BAD")<<"\n";
    }
//   system("pause");
    return 0;
}
