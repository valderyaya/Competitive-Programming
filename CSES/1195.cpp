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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,m;
vector<pii> v[100005];
ll dis[2][100005];
struct qwq{
    ll d;int x,f;
    bool operator<(const qwq &a)const{return d>a.d;}
};
priority_queue<qwq,vector<qwq>> q;
void dijkstra(){
    REP1(i,2,n) dis[0][i]=dis[1][i]=1e18;
    q.emplace(qwq{0,1,0});
    while(!q.empty()){
        auto u=q.top(); q.pop();
        if(u.d!=dis[u.f][u.x]) continue;
        for(auto &i:v[u.x]){
            if(dis[u.f][i.F]>u.d+i.S){
                dis[u.f][i.F]=u.d+i.S;
                q.emplace(qwq{dis[u.f][i.F],i.F,u.f});
            }
            if(u.f==0){
                if(dis[1][i.F]>u.d+i.S/2){
                    dis[1][i.F]=u.d+i.S/2;
                    q.emplace(qwq{dis[1][i.F],i.F,1});
                }
            }
        }
    }
}
signed main(){Aincrad
    cin>>n>>m;
    for(int x,y,z;m--;){
        cin>>x>>y>>z;
        v[x].em(y,z);
    }
    dijkstra();
    cout<<dis[1][n]<<"\n";
    return 0;
}
