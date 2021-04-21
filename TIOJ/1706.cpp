//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)


int n,m,st,ed,dis[100005],day,h[100005],cnt=0;
struct edge{int to,nxt,w,p;}e[200005];
void add(int u,int v,int w,int p){
    e[++cnt]=edge{v,h[u],w,p};
    h[u]=cnt;
}
int dijk(int now){
    REP1(i,1,n) dis[i]=1e10;
    dis[st]=0; int d,x,res=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.emplace(mkp(0,st));
    while(!q.empty()){
        tie(d,x)=q.top(); q.pop();
        if(d!=dis[x]) continue;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].w+(now?now*e[i].p:0);
            if(dis[v]>d+w){
                dis[v]=d+w;
                q.emplace(mkp(dis[v],v));
            }
        }
    }res=dis[ed];
    REP1(i,1,n) dis[i]=1e10;
    q.emplace(mkp(dis[ed]=0,ed));
    while(!q.empty()){
        tie(d,x)=q.top(); q.pop();
        if(d!=dis[x]) continue;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].w+(now?now*e[i].p:0);
            if(dis[v]>d+w){
                dis[v]=d+w;
                q.emplace(mkp(dis[v],v));
            }
        }
    }
    return res+dis[st];
}
int main(){Rosario
    cin>>n>>m>>st>>ed>>day;
    int x,y,c1,c2,p1,p2;
    while(m--){
        cin>>x>>y>>c1>>p1>>c2>>p2;
        add(x,y,c1,p1); add(y,x,c2,p2);
    }
    cout<<min(dijk(0),dijk(day-1))<<"\n";
    return 0;
}
