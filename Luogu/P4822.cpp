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
#define lb(x) (x&-x)

int n,m,k,dis[2605];
const int inf=1e9;
vector<pii> v[2605];
void dijkstra(){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    for(int i=2;i<=2600;++i) dis[i]=inf;
    q.emplace(0,1);
    while(!q.empty()){
        auto [d,u]=q.top(); q.pop();
        if(d!=dis[u]) continue;
        for(auto &i:v[u])
            if(dis[i.F]>d+i.S){
                dis[i.F]=d+i.S;
                q.emplace(dis[i.F],i.F);
            }
    }
    int ans=inf;
    for(int i=n,j=0;j<=k;i+=n,j++) ans=min(ans,dis[i]);
    cout<<ans<<"\n";
}
int main(){Rosario
    cin>>n>>m>>k;
    for(int x,y,xx,yy,c;m;--m){
        cin>>x>>y>>c;
        for(int i=0;i<=k;++i){
            xx=i*n+x,yy=i*n+y;
            v[xx].em(yy,c);
            v[yy].em(xx,c);
            if(i!=k){
                v[xx].em(yy+n,c/2);
                v[yy].em(xx+n,c/2);
            }
        }
    }
    // for(int i=1;i<=8;++i){
    //     cout<<i<<": ";
    //     for(auto &j:v[i]) cout<<j.F <<' ';
    //     cout<<"\n";
    // }
    dijkstra();
    return 0;
}
