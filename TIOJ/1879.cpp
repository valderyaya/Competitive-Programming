//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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


int now=0,cnt=0,low[10005],dep[10005],n,m;
vector<pii> edge;
vector<int> v[10005];
vector<vector<int>> bcc;
stack<int> st;
bitset<10005> vis;
inline void add(int a,int b){
    v[a].em(cnt++);
    edge.em(mkp(a,b));
    v[b].em(cnt++);
    edge.em(mkp(b,a));
}
void dfs(int x,int d,int re){
    vis[x]=1;low[x]=dep[x]=d;st.emplace(x);
    for(int i:v[x]){
        int u=edge[i].S;
        if(!vis[u]){
            dfs(u,d+1,i^1);
            low[x]=min(low[x],low[u]);
            if(dep[x]<low[u]){
                vector<int> tmp;
                for(int w=0;w!=u;st.pop()) w=st.top(),tmp.em(w);
                bcc.em(tmp);now++;
            }
        }else if(dep[u]<dep[x]&&i!=re) low[x]=min(low[x],dep[u]);
    }
}
int main(){Rosario
    cin>>n>>m;
    for(int a,b,i=0;i<m;i++) cin>>a>>b,add(a,b);
    REP(i,n) if(!vis[i]) dfs(i,0,-1);
    vector<int> tmp;
    while(!st.empty()) tmp.em(st.top()),st.pop();
    bcc.em(tmp);now++;
    REP(i,now) sort(ALL(bcc[i]));
    sort(ALL(bcc));
    REP(i,now){
        cout<<i+1<<": ";
        for(int j:bcc[i]) cout<<j<<' ';
        cout<<"\n";
    } 
//    system("pause");
    return 0;
}
