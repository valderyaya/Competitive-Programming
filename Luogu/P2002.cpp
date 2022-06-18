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
#define wait system("pause");

const int maxn=100005;
const int maxm=500005;
struct edge{int to,nxt;}e1[maxm];
int h1[maxn],cnt=0,n,m,dfn=0,dep[maxn],low[maxn],col=0,c[maxn],ans=0,r[maxn]={};
bitset<maxn> in;
stack<int> st;
void add(int u,int v){
    e1[++cnt].nxt=h1[u];
    e1[cnt].to=v;
    h1[u]=cnt;
}
void dfs(int x){
    dep[x]=low[x]=++dfn;
    st.emplace(x);in[x]=1;
    for(int i=h1[x];i;i=e1[i].nxt){
        if(!dep[e1[i].to]) dfs(e1[i].to),low[x]=min(low[x],low[e1[i].to]);
        else if(dep[e1[i].to]<dep[x]&&in[e1[i].to]) low[x]=min(low[x],dep[e1[i].to]);
    }
    if(dep[x]==low[x]){++col;
        for(int u=0;u!=x;st.pop()) u=st.top(),c[u]=col,in[u]=0;
    }
}
void build(){
    REP1(i,1,n)
        for(int j=h1[i];j;j=e1[j].nxt)
            if(c[i]!=c[e1[j].to]) r[c[e1[j].to]]++;
}

int main(){Rosario
    cin>>n>>m;
    for(int a,b,i=0;i<m;++i){
        cin>>a>>b;
        if(a!=b) add(a,b);
    }
    REP1(i,1,n) if(!dep[i]) dfs(i);
    build();
    REP1(i,1,col) if(r[i]==0) ans++;
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
