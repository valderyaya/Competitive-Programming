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
int n,m,q,k;
vector<int> v[150005];
bitset<150005> vis;
queue<pii> qe;
int bfs(int p){
    while(!qe.empty()) qe.pop();
    qe.push(mkp(p,0));
    int res=0;
    vis[p]=1;
    while(!qe.empty()){
        auto x=qe.front(); qe.pop();
        res+=x.F;
        for(auto &i:v[x.F]) if(!vis[i]&&x.S<k) vis[i]=1,qe.push(mkp(i,x.S+1));
    }
    return res;
}
signed main(){valder
    cin>>n>>m;
    for(int x,y,i=0;i<m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>q;
    for(int x;q--;){
        vis.reset();
        cin>>x>>k;
        cout<<bfs(x)<<endl;
    }
}
