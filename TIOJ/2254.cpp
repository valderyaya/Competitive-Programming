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

const int z=1e5+5;
vector<pii> v[z];
int L,R,n,m,dfn[z],cnt,in[z];
struct edge{int x,y,w;}e[z];
vector<int> ans;
bool check(int mid, bool tp){
    REP1(i,1,n) in[i]=0;
    queue<int> q;
    int c=0;
    REP(i,m) if(e[i].w>mid) ++in[e[i].y];
    REP1(i,1,n) if(!in[i]) q.emplace(i);
    while(!q.empty()){
        int x=q.front(); q.pop();
        ++c;
        if(tp) dfn[x]=++cnt;
        for(auto &i:v[x]){
            if(i.S <= mid) continue;
            if(--in[i.F]==0) q.emplace(i.F);
        }
    }
    return c==n;
}
signed main(){StarBurstStream
    cin>>n>>m;
    REP(i,m){
        cin>>e[i].x>>e[i].y>>e[i].w;
        v[e[i].x].em(e[i].y, e[i].w);
        R=max(R,e[i].w);
    }
    while(L<R){
        int mid=L+R>>1;
        if(check(mid, 0)) R = mid;
        else L=mid+1;   
    }
    check(L, 1);
    REP(i,m)
        if(dfn[e[i].x] > dfn[e[i].y]) ans.em(i+1);
    cout << L << ' ' << ans.size()<<"\n";
    for(auto &i:ans) cout<<i<<"\n";
    return 0;
}
