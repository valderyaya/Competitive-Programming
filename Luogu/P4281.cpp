//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int n,m,dep[500005],lca[500005][20];
vector<int> v[500005];
void dfs(int x,int d,int p){
    dep[x]=d;
    for(auto &i:v[x]) if(i!=p) lca[i][0]=x,dfs(i,d+1,x);
}
void build(){
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++) lca[i][j]=lca[lca[i][j-1]][j-1];
}
int LCA(int a,int b){
    if(dep[a]>dep[b]) a^=b^=a^=b;
    for(int i=dep[b]-dep[a],k=0;i;i>>=1,k++)
        if(i&1) b=lca[b][k];
    if(a==b) return a;
    for(int i=19;i>=0;i--)
        if(lca[a][i]!=lca[b][i]) a=lca[a][i],b=lca[b][i];
    return lca[a][0];
}
int main(){Rosario
    cin>>n>>m;
    int a,b,c,d,w,w1,w2,w3;
    REP(i,n-1) cin>>a>>b,v[a].em(b),v[b].em(a);
    lca[1][0]=1;dfs(1,0,1);build();
    REP(i,m){
        cin>>a>>b>>c;
        w1=LCA(a,b),w2=LCA(b,c),w3=LCA(a,c);
        if(w1==w2) w=w3;
        else if(w1==w3) w=w2;
        else w=w1;
        d=dep[a]+dep[b]+dep[c]-dep[w1]-dep[w2]-dep[w3];
        cout<<w<<' '<<d<<"\n";
    }
//    system("pause");
    return 0;
}
