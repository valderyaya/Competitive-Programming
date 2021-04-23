#include<bits/stdc++.h>
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

ll dis[100005],dist[100005];
vector<pll> v[100005];
priority_queue<pll,vector<pll>,greater<pll>> q;
void dijk(ll x){
    while(!q.empty()) q.pop();
    q.emplace(mkp(0,x));dis[x]=0;
    while(!q.empty()){
        ll d=q.top().F,u=q.top().S;q.pop();
        if(dist[u]<d) continue;
        for(pll i:v[u]){
            ll t=d+i.S;
            if(t<dis[i.F]){
                dist[i.F]=dis[i.F];
                dis[i.F]=t;
                q.emplace(mkp(t,i.F));
            }
            if(dis[i.F]<t&&t<dist[i.F]) dist[i.F]=t,q.emplace(mkp(t,i.F));
        }
    }
}   
int main(){Rosario
    ll a,b,t,n,c,m,st,ed;
    cin>>t;
    while(t--){
        cin>>n>>m>>st>>ed;
        REP(i,n) v[i].clear(),dis[i]=dist[i]=1e16;
        REP(i,m) cin>>a>>b>>c,v[a].em(mkp(b,c));
        dijk(st);
        cout<<dist[ed]-dis[ed]<<"\n";
    }
//    system("pause");
    return 0;
}
