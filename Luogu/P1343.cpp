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
#define wait system("pause");

const int z=305,inf=1e9;
struct edge{int to,w,nxt;}e[15005];
int cnt=1,h[z],n,m,num,d[z],cur[z];
void add(int u,int v,int w){
    e[++cnt]=edge{v,w,h[u]};
    h[u]=cnt;
}
queue<int> q;
bool bfs(){
    REP1(i,1,n) d[i]=0,cur[i]=h[i];
    q.emplace(1); d[1]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(!d[v]&&e[i].w) d[v]=d[x]+1,q.emplace(v);
        }
    }
    return d[n];
}
int dfs(int x,int flow){
    if(!flow||x==n) return flow;
    int res=0,k;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(d[v]==d[x]+1&&(k=dfs(v,min(flow,e[i].w)))){
            e[i].w-=k,e[i^1].w+=k;
            res+=k,flow-=k;
            if(!flow) break;
        }
    }
    return res;
}
int dinic(){
    int sum=0,c=0;
    while(bfs()) c++,sum+=dfs(1,inf);
    return (c?sum:-1);
}
int main(){Rosario
    cin>>n>>m>>num;
    int a,b,c;
    REP(i,m) cin>>a>>b>>c,add(a,b,c),add(b,a,0);
    c=dinic();
    if(~c) cout<<c<<' '<<(num/c+!!(num%c))<<"\n";
    else cout<<"Orz Ni Jinan Saint Cow!\n";
//    system("pause");
    return 0;
}
