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
#define em emplace_back
 
const int z=2e5+5;
int n,sz[z];
ll ans[z];
vector<int> v[z];
void dfs(int x,int p,ll d){
    ans[1]+=d;
    sz[x]=1;
    for(auto &i:v[x]) if(i!=p) dfs(i,x,d+1),sz[x]+=sz[i];
}
void dfs2(int x,int p){
    for(auto &i:v[x]) if(i!=p){
        ans[i]=ans[x]+n-sz[i]*2;
        dfs2(i,x);
    }
}
signed main(){Rosario
    cin>>n;
    for(int x,y,i=1;i<n;++i){
        cin>>x>>y;
        v[x].em(y), v[y].em(x);
    }
    dfs(1,1,0);
    dfs2(1,1);
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" \n"[i==n];
    return 0;
}
