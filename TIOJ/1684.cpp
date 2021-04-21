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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1001;
bitset<z> grp[z],vis,bcc_c[z],color,odd;
vector<int> v[z],bcc[z];
int cbcc,n,m,low[z],dfn[z],cnt,ans;
void init(){
    cbcc=cnt=ans=0;
    REP1(i,1,n) v[i].clear(),bcc[i].clear(),grp[i].reset(),bcc_c[i].reset();
    vis.reset(); odd.reset();
    memset(dfn,0,sizeof(dfn)); memset(low,0,sizeof(low));
}
stack<int> st;
void dfs(int x,int p){
    vis[x]=1;
    int son=0;
    st.emplace(x);
    low[x]=dfn[x]=++cnt;
    for(auto &i:v[x])
        if(!vis[i]){
            ++son;
            dfs(i,x);
            low[x]=min(low[x],low[i]);
            if(dfn[x]<=low[i]){
                ++cbcc;
                for(int u=0;u!=i;st.pop()) u=st.top(),bcc[cbcc].em(u),bcc_c[cbcc][u]=1;
                bcc[cbcc].em(x), bcc_c[cbcc][x]=1;
            }
        }else if(i!=p) low[x]=min(low[x],dfn[i]);
}
bool draw(int x,int bc,bool col){
    if(!bcc_c[bc][x]) return 0;
    if(vis[x]) return col!=color[x];
    vis[x]=1; color[x]=col;
    for(auto &i:v[x]) if(draw(i,bc,!col)) return 1;
    return 0;
}
int main(){Rosario
    while(cin>>n>>m,n&&m){
        init();
        for(int x,y;m;--m) cin>>x>>y,grp[x][y]=grp[y][x]=1;
        REP1(i,1,n) REP1(j,1,n) if(!grp[i][j]&&i!=j) v[i].em(j);
        REP1(i,1,n) if(!vis[i]) dfs(i,i);
        REP1(i,1,cbcc){
            color.reset();vis.reset();
            bool res=draw(bcc[i][0],i,1);
            for(auto &j:bcc[i]) odd[j]=odd[j]||res;
        }
        REP1(i,1,n) if(!odd[i]) ++ans;
        cout<<ans<<"\n";
    }
    return 0;
}
