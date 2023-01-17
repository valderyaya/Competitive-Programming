#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
#define mkp make_pair
 
#define int ll
int n,q,dis[200001];
vector<pii> v[200001];
void dijk(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    REP1(i,2,n) dis[i]=1e18;
    pq.emplace(mkp(0,1));
    int x,d;
    while(!pq.empty()){
        tie(d,x) = pq.top(); pq.pop();
        //cout<<x<<' '<<d<<endl;
        if(dis[x]!=d) continue;
        for(auto &i:v[x]){
            if(dis[i.F]>d+i.S){
                dis[i.F]=d+i.S;
                pq.emplace(mkp(dis[i.F],i.F));
            }
        }
    }
}
signed main(){Rosario
    cin>>n>>q;
    for(int x,y,c;q--;) cin>>x>>y>>c,v[x].em(y,c);
    dijk();
    REP1(i,1,n) cout<<dis[i]<<" \n"[i==n];
}
