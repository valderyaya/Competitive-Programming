//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
#define wait system("pause");

int n,m,dis[5005],mx=0,rt;
vector<int> v[5005];
void dfs(int x,int p,int d){
    dis[x]=max(dis[x],d);
    if(dis[x]>mx) mx=dis[x],rt=x;
    for(auto &i:v[x]) if(i!=p) dfs(i,x,d+1);
}
int main(){Rosario
    int a,b,mi=1e9;;
    cin>>n>>m;
    REP(i,m) cin>>a>>b,v[a].em(b),v[b].em(a);
    dfs(1,1,0); dfs(rt,rt,0); dfs(rt,rt,0);
    REP1(i,1,n) mi=min(mi,dis[i]);
    REP1(i,1,n) if(dis[i]==mi) cout<<i<<' ';
    cout<<"\n";
    REP1(i,1,n) if(dis[i]==mx) cout<<i<<' ';
//    system("pause");
    return 0;
}
