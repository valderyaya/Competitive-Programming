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

const int z=4e5+5;
int n,m,pa[z],k,ans[z],a[z];
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
vector<int> v[z];
bitset<z> vis;
int main(){Rosario
    cin>>n>>m;
    for(int x,y;m;m--) cin>>x>>y,v[x].em(y),v[y].em(x);
    REP1(i,1,n) pa[i]=i;
    cin>>k; int cnt=n-k,x,y;
    REP1(i,1,k) cin>>a[i],vis[a[i]]=1;
    REP1(i,1,n) for(auto &j:v[i]) if(vis[i]==0&&vis[j]==0&&fin(i)!=fin(j)) --cnt,pa[fin(i)]=fin(j);
    ans[k+1]=cnt;
    for(int i=k;i;--i){
        ++cnt; vis[a[i]]=0;
        for(auto &j:v[a[i]]) if(vis[j]==0&&fin(a[i])!=fin(j)) --cnt,pa[fin(a[i])]=fin(j);
        ans[i]=cnt;
    }
    REP1(i,1,k+1) cout<<ans[i]<<"\n";
    return 0;
}
