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

const int inf=1e9;
int n,m,cnt=-1,s,t,h[105],d[105],cur[105];
struct edge{int to,w,nxt;}e[20005];
vector<pii> ve;
void add(int u,int v,int w){
    e[++cnt]=edge{v,w,h[u]};
    h[u]=cnt;
    e[++cnt]=edge{u,0,h[v]};
    h[v]=cnt;
}
queue<int> q;
bool bfs(){
    REP1(i,0,n+1) d[i]=0,cur[i]=h[i];
    q.emplace(s); d[s]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            if(!d[v]&&e[i].w) d[v]=d[x]+1,q.emplace(v);
        }
    }
    return d[t];    
}
int dfs(int x,int flow){
    if(!flow||x==t) return flow;
    int sum=0,k;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(d[v]==d[x]+1&&(k=dfs(v,min(e[i].w,flow)))){
            e[i].w-=k, e[i^1].w+=k;
            flow-=k; sum+=k;
            if(!flow) break;
        }
    }
    return sum;
}
int dinic(){
    int sum=0;
    while(bfs()) sum+=dfs(s,inf);
    return sum;
}
int main(){Rosario
    cin>>m>>n;s=0,t=n+1;
    int a,b;
    while(cin>>a>>b,a!=-1&&b!=-1) add(a,b,1),ve.em(mkp(a,cnt-1));;
    REP1(i,1,n)
        if(i<=m) add(s,i,1);
        else add(i,t,1);
    cout<<dinic()<<"\n";
    for(auto &i:ve) if(e[i.S].w==0) cout<<i.F<<' '<<e[i.S].to<<"\n";
//    system("pause");
    return 0;
}
