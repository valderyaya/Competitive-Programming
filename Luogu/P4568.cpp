//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)


int n,m,k,st,sd,dis[110005];
vector<pii> v[110005];
bool vis[110005];
inline void dijk(){
    REP(i,(k+1)*n) dis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii>> q;q.emplace(mkp(0,st));dis[st]=0;
    while(q.size()){
        int d=q.top().F,u=q.top().S;q.pop();
        if(vis[u]||dis[u]!=d) continue;
        vis[u]=1;
        for(auto i:v[u]){
            if(!vis[i.F]&&dis[i.F]>d+i.S){
                dis[i.F]=d+i.S;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
}
int main(){Rosario
    cin>>n>>m>>k>>st>>sd;
    int a,b,c;
    REP(i,m){
        cin>>a>>b>>c;
        REP1(i,0,k){
            v[a+i*n].em(mkp(b+i*n,c));
            v[b+i*n].em(mkp(a+i*n,c));
            if(i!=k){
                v[a+i*n].em(mkp(b+(i+1)*n,0));
                v[b+i*n].em(mkp(a+(i+1)*n,0));
            }
        }
    }dijk();
    int ans=1e9;
    REP1(i,0,k) ans=min(ans,dis[i*n+sd]);
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
