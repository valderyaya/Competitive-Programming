//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int ans,f[20][70000],n;
string s[20];
int dfs(int x,int v){
    if(~f[x][v]) return f[x][v];
    f[x][v]=0;
    REP(i,n) if(s[x].back()==s[i][0]&&(!(v&(1<<i)))) f[x][v]=max(f[x][v],dfs(i,v|(1<<i)));
    return f[x][v]+=s[x].size();
}
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>s[i];
    memset(f,-1,sizeof(f));
    REP(i,n) ans=max(ans,dfs(i,1<<i));
    cout<<ans<<"\n";
    return 0;
}
