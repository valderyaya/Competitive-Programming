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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long

#define int ll
int ans,n,k,now[100001];
vector<pii> v[100001];
void dfs(int x,int pa, int d){
    for(auto &i:v[x]){
        if(i.F==pa) continue;
        dfs(i.F,x, i.S);
    }
    int df= k-now[x];
    now[pa] -= df;
    now[x] += df;
    ans += abs(df)*d;
}
signed main(){StarBurstStream
    cin>>n>>k;
    REP1(i,1,n) cin>>now[i];
    for(int x,y,w,i=1;i<n;++i){
        cin>>x>>y>>w;
        v[x].em(y,w);
        v[y].em(x,w);
    }
    dfs(1,1,0);
    cout<<ans<<"\n";
    return 0;
}
