//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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

#define int ll
const int mod=1e9+7;
int f[2][100001],n;
vector<int> v[100001];
void dfs(int x,int pa){
    f[0][x]=f[1][x]=1;
    for(auto &i:v[x]){
        if(i==pa) continue;
        dfs(i,x);
        f[1][x]=f[1][x]*f[0][i]%mod;
        f[0][x]=f[0][x]*(f[0][i]+f[1][i])%mod;
    }
}
signed main(){StarBurstStream
    cin>>n;
    for(int x,y,i=1;i<n;++i){
        cin>>x>>y;
        v[x].em(y);
        v[y].em(x);
    }
    dfs(1,0);
    cout<<(f[0][1]+f[1][1])%mod<<"\n";
}
