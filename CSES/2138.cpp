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
 
int n,m,in[50001];
bitset<50001> a[50001];
vector<int> v[50001];
queue<int> q;
signed main(){StarBurstStream
    cin>>n>>m;
    for(int x,y,i=0;i<m;++i) cin>>x>>y, v[y].em(x), ++in[x];
    REP1(i,1,n) if(!in[i]) a[i].set(i),q.emplace(i);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &y:v[x]){
            a[y]|=a[x];
            if(--in[y]==0) a[y].set(y), q.emplace(y);
        }
    }
    REP1(i,1,n) cout<<a[i].count()<<' ';
}
