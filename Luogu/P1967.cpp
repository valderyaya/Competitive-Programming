#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
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
//#define lb(x) (x&-x)

struct qq{
    int a,b,c;
    bool operator<(const qq &x)const{
        return c>x.c;
    }
}q[50005];
int n,m,pa[10005],dep[10005],lca[10005][20],mx[10005][20],query;
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
vector<pii> v[10005];
void dfs(int x,int d,int p){
    dep[x]=d;
    for(pii i:v[x]){
        if(i.F!=p){
            lca[i.F][0]=x;mx[i.F][0]=i.S;
            dfs(i.F,d+1,x);
        }
    }
}
void build(){
    REP1(i,1,n) lca[i][0]=-1;
    REP1(i,1,n){
        if(lca[i][0]==-1){
            lca[i][0]=i;mx[i][0]=1e9;dfs(i,0,i);
        }
    }
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++) lca[i][j]=lca[lca[i][j-1]][j-1],mx[i][j]=min(mx[i][j-1],mx[lca[i][j-1]][j-1]);
}
int LCA(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    int ret=1e9;
    for(int i=dep[b]-dep[a],k=0;i;i>>=1,k++){
        if(i&1) ret=min(ret,mx[b][k]),b=lca[b][k];
    }
    if(a==b) return ret;
    for(int i=19;i>=0;i--){
        if(lca[a][i]!=lca[b][i]){
            ret=min(ret,min(mx[b][i],mx[a][i]));
            a=lca[a][i];b=lca[b][i];
        }
    }
    return min(ret,min(mx[a][0],mx[b][0]));
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n){
    //    REP(j,20) mx[i][j]=1e9;
        pa[i]=i;
    }
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].c;
    sort(q,q+m);
    REP(i,m){
        int a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b){
            pa[a]=b;
            v[q[i].a].em(mkp(q[i].b,q[i].c));v[q[i].b].em(mkp(q[i].a,q[i].c));
        }
    }build();
    cin>>query;int a,b,c;
    while(query--){
        cin>>a>>b;
        if(fin(a)!=fin(b)) cout<<"-1\n";
        else cout<<LCA(a,b)<<"\n";
    }
//    system("pause");
    return 0;
}
