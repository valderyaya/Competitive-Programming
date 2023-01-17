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
 
int n,dp[200001],tot;
vector<int> v[200001];
void dfs(int x,int p){
    for(auto &i:v[x]){
        if(i!=p){
            dfs(i,x);
            if(!dp[i]&&!dp[x])++tot,dp[i]=dp[x]=1;            
        }
    }
}
signed main(){Rosario
    cin>>n;
    for(int i=1,x,y;i<n;++i) cin>>x>>y,v[x].em(y),v[y].em(x);
    dfs(1,1);
    cout<<tot<<"\n";
}
