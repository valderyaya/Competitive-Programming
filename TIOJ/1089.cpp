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

int n,m,mp[505],ans=0,mq[505];
bitset<505> vis;
vector<int> v[505];
bool dfs(int x){
    vis[x]=1;
    for(auto &i:v[x])
        if(!~mq[i]||!vis[mq[i]]&&dfs(mq[i]))
            return mq[mp[x]=i]=x,1;
    return 0;
}
int main(){Rosario
    cin>>n>>m;
    int x,y;memset(mp,-1,sizeof(mp));memset(mq,-1,sizeof(mq));
    while(m--) cin>>x>>y,v[x].em(y);
    REP1(i,1,n) if(vis.reset(),dfs(i)) ans++;
    cout<<ans<<"\n";
    return 0;
}
