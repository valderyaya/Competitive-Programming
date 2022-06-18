//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e6+5;
int n,d[z];
ll ans=0;
vector<pii> v[z];
void dfs(int x,int p){
    d[x]=1;
    for(auto &i:v[x]) if(i.F!=p){
        dfs(i.F,x);
        ans+=(ll)abs(n-d[i.F]-d[i.F])*i.S;
        d[x]+=d[i.F];
    } 
}
int main(){Rosario
    cin>>n;
    for(int x,y,c,i=1;i<n;++i) cin>>x>>y>>c,v[x].em(mkp(y,c)),v[y].em(mkp(x,c));
    dfs(1,1);  cout<<ans<<"\n";
    return 0;
}
