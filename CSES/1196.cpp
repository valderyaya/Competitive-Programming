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
const int z=1e5+5;
int k,n,m;
vector<pii> v[z];
vector<int> ans;
priority_queue<pii,vector<pii>,greater<pii>> q;
priority_queue<int> pq[z];
signed main(){Rosario
    cin>>n>>m>>k;
    for(int x,y,c;m--;){
        cin>>x>>y>>c;
        v[x].em(y,c);
    }
    pq[1].emplace(0); q.push({0,1});
    while(!q.empty()){
        auto x=q.top(); q.pop();
        //cout<<x.F<<' '<<x.S<<endl;
        if(x.F>pq[x.S].top()) continue;
        for(auto &i:v[x.S]){
            int dis=x.F+i.S;
            if(pq[i.F].size()<k) {
                pq[i.F].emplace(dis);
                q.push({dis,i.F});
            }else if(dis<pq[i.F].top()){
                pq[i.F].pop();
                pq[i.F].emplace(dis);
                q.push({dis,i.F});
            }
        }
    }
    while(k--){
        ans.em(pq[n].top());
        pq[n].pop();
    }
    reverse(ALL(ans));
    for(auto &i:ans) cout<<i<<' ';
}
