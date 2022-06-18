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
struct edge{
    int to,w,rev;
    edge(int x,int y,int r):to(x),w(y),rev(r){}
};
vector<edge> v[55];
int d[55],cur[55],n,cnt=0,s,t,m[130];
void add(int u,int to,int w){
    v[u].em(edge(to,w,v[to].size()));
    v[to].em(edge(u,0,v[u].size()-1));
}
queue<int> q;
bool bfs(){
    memset(cur,0,sizeof(cur));
    memset(d,0,sizeof(d));
    q.emplace(s); d[s]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        REP(i,v[x].size())
            if(!d[v[x][i].to]&&v[x][i].w)
                q.emplace(v[x][i].to),d[v[x][i].to]=d[x]+1;
    }
    return d[t];
}
int dfs(int x,int flow){
    if(!flow||x==t) return flow;
    int sum=0,k;
    for(int &i=cur[x];i<v[x].size();++i){
        edge &e=v[x][i];
        if(d[e.to]==d[x]+1&&(k=dfs(e.to,min(e.w,flow)))){
            e.w-=k;
            v[e.to][e.rev].w+=k;
            sum+=k; flow-=k;
            if(!flow) break;
        }
    }
    return sum;
}
int dinic(){
    int ret=0;
    while(bfs()) ret+=dfs(s,inf);
    return ret;
}
int main(){Rosario
    cin>>n;
    for(int i='A';i<='Z';i++) m[i]=++cnt;
    s=1,t=cnt;
    for(int i='a';i<='z';i++) m[i]=++cnt;
    char a,b;
    int c;
    REP(i,n) cin>>a>>b>>c,add(m[a],m[b],c);
    cout<<dinic()<<"\n";
//    system("pause");
    return 0;
}
