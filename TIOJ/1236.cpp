//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
#include<iostream>
#include<queue>
#include<vector>
#include<bitset>
#include <string.h>
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

const int inf=2147483647,mn=1002;
struct edge{
    int v,w,rev;
    edge(int x,int y,int z):v(x),w(y),rev(z){}
};
int n,m,d[mn],cur[mn],t;
bitset<mn> in,out;
vector<edge> ed[mn];
void add(int u,int v,int w){
    ed[u].em(edge(v,w,ed[v].size()));
    ed[v].em(edge(u,0,ed[u].size()-1));
}
queue<int> q;
bool bfs(){
    memset(d,0,sizeof(d));
    memset(cur,0,sizeof(cur));
    q.emplace(0); d[0]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        REP(i,ed[x].size()){
            edge &e=ed[x][i];
            if(!d[e.v]&&e.w) q.emplace(e.v),d[e.v]=d[x]+1;
        }
    }
    return d[t];
}
int dfs(int x,int flow){
    if(!flow||x==t) return flow;
    int sum=0,k;
    for(int &i=cur[x];i<ed[x].size();++i){
        edge &e=ed[x][i];
        if(d[e.v]==d[x]+1&&(k=dfs(e.v,min(e.w,flow)))){
            e.w-=k;
            ed[e.v][e.rev].w+=k;
            sum+=k; flow-=k;
            if(!flow) return sum;
        }
    }
    return sum;
}
int dinic(){
    int sum=0;
    while(bfs()) sum+=dfs(0,inf);
    return sum;
}
int main(){Rosario
    cin>>n; t=n<<1|1;
    int x,y;
    REP(i,n) cin>>x,add(i<<1|1,i<<1+2,x);
    cin>>m;
    while(m--) cin>>x>>y,--x,--y,add(x<<1+2,y<<1|1,inf),out[x]=1,in[y]=1;
    REP(i,n){
        if(!in[i]) add(0,i<<1|1,inf);
        if(!out[i]) add(i<<1+2,t,inf);
    }
    cout<<dinic()<<"\n";
//    system("pause");
    return 0;
}
