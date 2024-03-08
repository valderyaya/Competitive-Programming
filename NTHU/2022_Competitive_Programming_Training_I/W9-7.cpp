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
 
const int z=1e5+5;
int n,m,in[z];
queue<int> q;
vector<int> v[z],ans;
signed main(){Rosario
    cin>>n>>m;
    for(int x,y;m--;) cin>>x>>y,v[x].em(y),++in[y];
    REP1(i,1,n) if(!in[i]) q.emplace(i),ans.em(i);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &i:v[x]) if(--in[i]==0) q.emplace(i),ans.em(i);
    }
    if(ans.size()!=n) cout<<"IMPOSSIBLE\n" ;
    else for(auto &i:ans) cout<<i<<' ';
}
