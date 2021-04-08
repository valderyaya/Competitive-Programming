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

const int z=10005;
vector<int> v[z];
vector<int> r[z];
int ans=0,n,m,dis[z],a[z],in[z]={},out[z]={},val[z];
bitset<z> vis;
void dfs(int x){
    if(vis[x]) return;
    ++ans; vis[x]=1;
    vector<int> mx;
    for(auto &i:r[x]){
        if(mx.empty()||val[i]>val[mx[0]]) mx.clear(),mx.em(i);
        else if(val[i]==val[mx[0]]) mx.em(i);
    }
    for(auto &i:mx) dfs(i);
}
int main(){Rosario
    cin>>n>>m; int x,y;
    REP1(i,1,n) cin>>a[i];
    while(m--) cin>>x>>y,v[x].em(y),r[y].em(x),++in[y],++out[x];
    queue<int> q;
    REP1(i,1,n){
        if(in[i]==0) q.emplace(i),val[i]=a[i];
        if(out[i]==0) r[0].em(i);
    }
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &i:v[x]){
            --in[i];
            if(in[i]==0) q.emplace(i);
            val[i]=max(val[i],a[i]+val[x]);
        }
    }
    //REP1(i,1,n) cout<<val[i]<<" \n"[i==n];
    dfs(0);
    cout<<ans-1<<"\n";
    return 0;
}
