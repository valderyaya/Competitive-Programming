#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define ll long long

struct edge{int to,nxt,flow;}e[1000005];
int cur[2005],n,m,ed=1502,st,k,h[2005],cnt=1,d[2005];
bitset<2005> vis;
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
queue<int> q;
bool bfs(){
    vis.reset();
    REP1(i,0,1505) cur[i]=h[i],d[i]=0;
    q.emplace(st); d[st]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(!d[v]&&e[i].flow){
                d[v]=d[x]+1;
                q.emplace(v);
            }
        }
    }
    return d[ed];
}
int dfs(int x,int flow){
    if(x==ed||!flow) return flow;
    int res=0,k; vis[x]=1;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(!vis[v]&&e[i].flow&&d[v]==d[x]+1){
            k=dfs(v,min(e[i].flow,flow));
            flow-=k, res+=k;
            e[i].flow-=k, e[i^1].flow+=k;
        }
        if(!flow) break;
    }
    vis[x]=0;
    return res;
}
int dinic(){
    int res=0;
    while(bfs()) res+=dfs(st,1e9);
    return res;
}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int x,y,i=1;i<=n;++i){
        cin>>x;
        add(st,i,1); add(i,st,0);
        while(x--) cin>>y,add(i,500+y,1),add(500+y,i,0);
    }
    add(st,1005,k); add(1005,st,0);
    for(int j=1;j<=n;++j) add(1005,j,1),add(j,1005,0);
    REP1(i,1,m) add(i+500,ed,1),add(ed,i+500,0);
    cout<<dinic()<<"\n";
}

