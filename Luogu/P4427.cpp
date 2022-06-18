#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)
#define wait system("pause");

#define int ll
const int mod=998244353,z=300001;
int power(int a,int n){
    int res=1;
    for(;n;n>>=1,a=a*a%mod) if(n&1) res=res*a%mod;
    return res%mod;
}
int n,m,dep[z],lca[z][22],val[z][55];
vector<int> v[z];
inline void build(){
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++) lca[i][j]=lca[lca[i][j-1]][j-1];
}
void dfs(int x,int p){
    dep[x]=dep[p]+1;
    lca[x][0]=p;
    REP1(i,1,50) val[x][i]=(val[p][i]+power(dep[x],i))%mod;
    for(auto &i:v[x]) if(i!=p) dfs(i,x);
}
int fin(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    for(int i=dep[b]-dep[a],k=0;i;i>>=1,k++) if(i&1) b=lca[b][k];
    if(a==b) return a;
    for(int i=20;~i;--i) if(lca[a][i]!=lca[b][i]) a=lca[a][i],b=lca[b][i];
    return lca[a][0];
}
main(){Rosario
    int a,b,c,x;
    cin>>n;
    REP(i,n-1) cin>>a>>b,v[a].em(b),v[b].em(a);
    dep[x]=-1;dfs(1,0);build();
//    REP1(i,1,n) REP1(j,1,4) cout<<val[i][j]<<" \n"[j==4];
    cin>>m;
    while(m--) cin>>a>>b>>c,x=fin(a,b),cout<<((val[a][c]+val[b][c])%mod-(val[x][c]+val[lca[x][0]][c])%mod+mod)%mod<<"\n";
//    wait
}
