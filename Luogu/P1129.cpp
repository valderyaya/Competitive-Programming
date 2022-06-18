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

const int z=405;
struct edge{int to,w,nxt;}e[170000];
int h[z],cur[z],cs,s,t,d[z],n,cnt;
void add(int u,int v,int w){
    e[++cnt]=edge{v,w,h[u]};
    h[u]=cnt;
    e[++cnt]=edge{u,0,h[v]};
    h[v]=cnt;
}
queue<int> q;
bool bfs(){
    REP1(i,0,n<<1|1) cur[i]=h[i],d[i]=0;
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
    int k,res=0;
    for(int &i=cur[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(d[v]==d[x]+1&&(k=dfs(v,min(flow,e[i].w)))){
            flow-=k,res+=k;
            e[i].w-=k,e[i^1].w+=k;
            if(!flow) break;
        }
    }
    return res;
}
void init(){
    REP1(i,0,n<<1|1) h[i]=0;
    cnt=1;
}
int dinic(){
    int sum=0;
    while(bfs()) sum+=dfs(s,1e9);
    return sum;
}
int main(){Rosario
    cin>>cs;
    while(cs--){
        cin>>n; s=0,t=n<<1|1;
        init(); int x;
        REP1(i,1,n) add(s,i,1),add(i+n,t,1);
        REP1(i,1,n) REP1(j,1,n){
            cin>>x;
            if(x) add(i,j+n,1);
        }
        cout<<(dinic()>=n?"Yes":"No")<<"\n";
    }
//    system("pause");
    return 0;
}
