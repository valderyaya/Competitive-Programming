//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";

const int mod=100003;
struct edge{int to,nxt;}e[2000005];
int h[1000005],dis[1000005],n,m,ans[1000005],cnt=0;
priority_queue<pii,vector<pii>,greater<pii>> q;
map<pii,int> ma;
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dijk(){
    REP1(i,2,n) dis[i]=1e9;
    q.emplace(mkp(0,1));ans[1]=1;
    while(!q.empty()){
        int d=q.top().F,x=q.top().S;q.pop();
        if(dis[x]!=d) continue;
        for(int i=h[x];i;i=e[i].nxt){
            int w=d+1,v=e[i].to;
            if(dis[v]>w) {
                dis[v]=w,ans[v]=(ans[x]*ma[{x,v}]%mod)%mod;
                q.emplace(mkp(w,v));
            }else if(dis[v]==w) ans[v]=(ans[v]+ans[x]*ma[{x,v}]%mod)%mod;
        }
    }
}
int main(){Rosario
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        ma[{a,b}]++,ma[{b,a}]++;
        if(ma[{a,b}]==1) add(a,b),add(b,a);
    }
    dijk();
    cout<<1<<"\n";
    REP1(i,2,n) cout<<(dis[i]==1e9?0:ans[i])<<"\n";
//    system("pause");
    return 0;
}
