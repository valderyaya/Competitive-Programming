//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
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


struct qq{
    int a,b,c;
    bool operator<(const qq &q)const{
        return c<q.c;
    }
}q[50005];
int pa[30005],lca[30005][20],n,m,mx[30005][20],dep[30005];
vector<pii> v[30005];
void dfs(int x,int d,int p){
    dep[x]=d;
    for(pii i:v[x]){
        if(i.F!=p){
            mx[i.F][0]=i.S;lca[i.F][0]=x;
            dfs(i.F,d+1,x);
        }
    }
}
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void build(){
    REP1(i,1,n) lca[i][0]=-1;
    REP1(i,1,n){
        if(lca[i][0]==-1){
            lca[i][0]=i;
            mx[i][0]=0;
            dfs(i,0,i);
        }
    }
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++){
            lca[i][j]=lca[lca[i][j-1]][j-1];
            mx[i][j]=max(mx[i][j-1],mx[lca[i][j-1]][j-1]);
        }
}
int LCA(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    int ma=0;
    for(int i=dep[b]-dep[a],k=0;i;i>>=1,k++){
        if(i&1){
            ma=max(ma,mx[b][k]);
            b=lca[b][k];
        }
    }
    if(a==b) return ma;
    for(int i=19;i>=0;i--){
        if(lca[a][i]!=lca[b][i]){
            ma=max(ma,max(mx[a][i],mx[b][i]));
            a=lca[a][i],b=lca[b][i];
        }
    }
    return max(ma,max(mx[a][0],mx[b][0]));
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) pa[i]=i;
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].c;
    sort(q,q+m);
    REP(i,m){
        int a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b){
            pa[a]=b;
            v[q[i].a].em(mkp(q[i].b,q[i].c));
            v[q[i].b].em(mkp(q[i].a,q[i].c));
        }
    }
    build();
    int k;
    cin>>k;
    for(int a,b,i=0;i<k;i++){
        cin>>a>>b;
        if(fin(a)!=fin(b)) cout<<"-1\n";
        else cout<<LCA(a,b)<<"\n";
    }
//    system("pause");
    return 0;
}
