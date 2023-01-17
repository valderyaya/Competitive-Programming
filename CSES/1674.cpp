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
 
int n,sz[200001];
vector<int>v[200001];
void dfs(int x){
    sz[x]=1;
    for(auto &i:v[x]){
        dfs(i);
        sz[x]+=sz[i];
    }
}
signed main(){Rosario
    cin>>n;
    for(int i=2,x;i<=n;++i) cin>>x,v[x].em(i);
    dfs(1);
    REP1(i,1,n) cout<<sz[i]-1<<" \n"[i==n];
}
