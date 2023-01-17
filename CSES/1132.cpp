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
int n,dp[2][z];
vector<int> v[z];
int dfs(int x,int p,int d,int o){
    dp[o][x]=d;
    int ret=-1, j;
    for(auto &i:v[x])
        if(i!=p){
            j=dfs(i,x,d+1,o);
            if(!~ret||dp[o][ret]<dp[o][j]) ret=j;
        }
    return !~ret?x:ret;
}
signed main(){Rosario
    cin>>n;
    for(int x,y,i=1;i<n;++i){
        cin>>x>>y;
        v[x].em(y), v[y].em(x);
    }
    int n1=dfs(1,1,0,0);
    int n2=dfs(n1,n1,0,0);
    dfs(n2,n2,0,1);
    for(int i=1;i<=n;++i)
        cout<<max(dp[0][i],dp[1][i])<<" \n"[i==n];
    return 0;
}
