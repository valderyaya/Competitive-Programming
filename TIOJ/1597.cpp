//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)


struct qwq{int to,nxt;ll w,p;}e[160006];
int h[40004],cnt,n,m,day;
ll d[40004];
void add(int u,int v,ll w,ll p){
    e[++cnt]=qwq{v,h[u],w,p};
    h[u]=cnt;
}
queue<ll> q;
bitset<40004> vis;
ll spfa(int st,int ed,ll now){
    memset(d,-1,sizeof(d));
    vis.reset(); vis[st]=1;
    d[st]=0; q.emplace(st); 
    while(!q.empty()){
        int x=q.front(); q.pop(); vis[x]=0;
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to; 
            ll w=e[i].w+e[i].p*now;
            if(d[v]==-1||d[v]>d[x]+w){
                d[v]=d[x]+w;
                if(!vis[v]) q.emplace(v),vis[v]=1;
            }
        }
    }
    return d[ed];
}
int st,ed;
ll cal(ll mid){return spfa(st,ed,mid)+spfa(ed,st,mid);}
void rd(ll &x){
    x=0;register int f=1;
    register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    x*=f;
}
int main(){//Rosario
    cin>>n>>m>>st>>ed>>day;
    for(ll n1,n2,c1,c2,p1,p2;m;m--){
        rd(n1),rd(n2),rd(c1),rd(p1),rd(c2),rd(p2);
        add(n1,n2,c1,p1);
        add(n2,n1,c2,p2);
    }
    ll ans=0;
    for(int i=1<<29;i;i>>=1){
        if(ans+i>=day) continue;
        ll c1=cal(ans+i-1),c2=cal(ans+i);
        if(c1<=c2) ans+=i;
        if(c1==c2) break;
    }
    printf("%lld\n",cal(ans)-min(cal(0),cal(day-1)));
    return 0;
}
