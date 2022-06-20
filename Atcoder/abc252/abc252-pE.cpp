#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

#define int ll
int n,m,dis[200005],ans[200005];
vector<tuple<ll,ll,ll>> v[200005];
void dijk(){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    fill(dis+1,dis+1+n,1e18);
    pq.emplace(mkp(dis[1]=0,1));
    while(!pq.empty()){
        auto [d,x]=pq.top();
        pq.pop();
        if(d!=dis[x]) continue;
        for(auto &[to,c,id]:v[x]){
            if(dis[to]>d+c){
                ans[to]=id;
                dis[to]=d+c;
                pq.emplace(mkp(dis[to],to));
            }
        }
    }
    //for(int i=1;i<=n;++i) cout<<dis[i]<<" \n"[i==n];
}
signed main(){valder
    cin>>n>>m;
    for(int x,y,c,i=1;i<=m;++i){
        cin>>x>>y>>c;
        v[x].em(y,c,i);
        v[y].em(x,c,i);
    }
    dijk();
    for(int i=2;i<=n;++i) cout<<ans[i]<<' ';
}
