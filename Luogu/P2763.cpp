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

struct edge{int from,to,nxt,flow;}e[50005];
int n,k,cnt=1,dis[50005],h[50005],cur[50005],st=50002,ed=50003,ste,ede,ck;
void add(int u,int v,int f){
    e[++cnt]=edge{u,v,h[u],f};
    h[u]=cnt;
}
queue<int> q;
vector<int> v[3005];
bool bfs(){
    REP1(i,1,k+n) dis[i]=0,cur[i]=h[i];
    dis[st]=dis[ed]=0,cur[st]=h[st],cur[ed]=h[ed];
    q.emplace(st);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=h[x];i;i=e[i].nxt){
            int to=e[i].to,f=e[i].flow;
            if(f&&!dis[to]){
                dis[to]=dis[x]+1;
                q.emplace(to);
            }
        }
    }
    return dis[ed];
}
int dfs(int x,int f){
    if(!f||x==ed) return f;
    int flow=0,k;
    for(int &i=cur[x];i;i=e[i].nxt){
        int to=e[i].to,fl=e[i].flow;
        if(dis[to]==dis[x]+1&&(k=dfs(to,min(f,fl)))){
            e[i].flow-=k,e[i^1].flow+=k;
            flow+=k,f-=k;
            if(!f) break;
        }
    }
    return flow;
}
int dinic(){
    int res=0;
    while(bfs()) res+=dfs(st,1e9);
    return res==ck;
}
int main(){Rosario
    cin>>k>>n;
    for(int x,i=1;i<=k;++i){
        cin>>x;
        add(i,ed,x);
        add(ed,i,0);
        ck+=x;
    }
    ste=cnt+1;
    for(int p,x,i=1;i<=n;++i){
        cin>>p;
        while(p--){
            cin>>x;
            add(i+k,x,1);
            add(x,i+k,0);
        }
    }
    ede=cnt;
    for(int i=1;i<=n;++i){
        add(st,i+k,1);
        add(i+k,st,0);
    }
    if(dinic()){
        for(int i=ste;i<=ede;i+=2)
            if(e[i].flow==0) v[e[i].to].em(e[i].from-k);
        for(int i=1;i<=k;++i){
            cout<<i<<": ";
            for(auto &j:v[i]) cout<<j<<' ';
            cout<<"\n";
        }
    }else cout<<"No Solution!\n";
}
