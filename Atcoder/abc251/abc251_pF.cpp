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

const int z=2e5+5;
int n,m;
vector<pii> a,b;
vector<int> v[z];
bitset<z> vis;
void dfs(int x){
    vis[x]=1;
    for(auto &i:v[x]){
        if(!vis[i]){
            a.em(mkp(x,i));
            dfs(i);
        }
    }
}
void bfs(){
    vis.reset();
    queue<int> q;
    q.emplace(1);
    vis[1]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &i:v[x]){
            if(!vis[i]){
                vis[i]=1;
                b.em(mkp(x,i));
                q.emplace(i);
            }
        }
    }
}
signed main(){valder
    cin>>n>>m;
    for(int x,y;m--;){
        cin>>x>>y;
        v[x].em(y);
        v[y].em(x);
    }
    dfs(1);
    bfs();
    for(auto &i:a) cout<<i.F<<' '<<i.S<<"\n";
    for(auto &i:b) cout<<i.F<<' '<<i.S<<"\n";
    return 0;
}
