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

const int z=225;
int pay,m,n,f,st,dis[z];
vector<pii> v[z];
int dijk(){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    int cnt[z],d,x; q.emplace(mkp(pay,st)); dis[st]=pay;
    while(!q.empty()){
        tie(d,x)=q.top(); q.pop();
        if(dis[x]!=d) continue;
        if(++cnt[x]==n) return -1;
        for(auto &i:v[x]){
            if(dis[i.F]<d+i.S){
                dis[i.F]=d+i.S;
                q.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
    return *max_element(dis+1,dis+1+n);
}
int main(){Rosario
    cin>>pay>>m>>n>>f>>st;
    int x,y,c;
    while(m--) cin>>x>>y,v[x].em(mkp(y,pay));
    while(f--) cin>>x>>y>>c,v[x].em(mkp(y,pay-c));
    cout<<dijk()<<"\n";
    return 0;
}
