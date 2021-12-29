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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
#define int ll
const int z=2e5+5;
int a[z],out[z],in[z],tot,n,m,bit[z];
void add(int x,int v){
    for(;x<=n;x+=lb(x)) bit[x]+=v;
}
int qry(int x){
    int ret=0;
    for(;x;x-=lb(x)) ret+=bit[x];
    return ret;
}
vector<int> v[z];
void dfs(int x,int p){
    in[x]=++tot;
    for(auto &i:v[x])
        if(i!=p) dfs(i,x);
    out[x]=tot;
}
signed main(){Aincrad
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i];
    for(int i=1,x,y;i<n;++i) cin>>x>>y,v[x].em(y),v[y].em(x);
    dfs(1,1);
    REP1(i,1,n) add(in[i],a[i]);
    for(int k,s,x;m--;){
        cin>>k>>s;
        if(k==1) cin>>x,add(in[s],-a[s]),add(in[s],a[s]=x);
        else cout<<qry(out[s])-qry(in[s]-1)<<"\n";
    }
    return 0;
}
