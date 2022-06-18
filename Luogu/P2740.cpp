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

const int z=1005,inf=1e9+5;
int cnt=1,dep[z],n,m,w[z][z];
queue<int> q;
bool bfs(){
    q.emplace(1);
    memset(dep,0,sizeof(dep));
    dep[1]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        REP1(i,1,m) if(!dep[i]&&w[x][i]) q.emplace(i),dep[i]=dep[x]+1;
    }
    return dep[m];
}
int dfs(int x,int flow){
    if(flow==0||x==m) return flow;
    int k;
    REP1(i,1,m){
        if(dep[i]==dep[x]+1&&(k=dfs(i,min(w[x][i],flow)))){
            w[x][i]-=k, w[i][x]+=k;
            return k;
        }
    }
    return 0;
}
int dinic(){
    int sum=0;
    while(bfs()) sum+=dfs(1,inf);
    return sum;
}
int main(){Rosario
    cin>>n>>m;
    int a,b,c;
    REP(i,n) cin>>a>>b>>c,w[a][b]+=c;
    cout<<dinic()<<"\n";
//    system("pause");
    return 0;
}
