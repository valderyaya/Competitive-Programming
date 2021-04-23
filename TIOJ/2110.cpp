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

const int z=1e5+1;
struct edge{int to,nxt,w;}e[z<<1];
int in[2][18][z],dep[z],de[2][18][z],h[z],cnt=0,n,q,lca[18][z];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
void dfs(int x){
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(dep[v]) continue;
        in[0][0][v]=in[1][0][v]=de[0][0][v]=de[1][0][v]=e[i].w;
        lca[0][v]=x; dep[v]=dep[x]+1; dfs(v);
    }
}
void build(){
    for(int j=1;j<18;++j)
        for(int i=1;i<=n;++i){
            lca[j][i]=lca[j-1][lca[j-1][i]];
            int pa=lca[j-1][i];
            if(in[0][j-1][i]!=-1&&in[0][j-1][pa]!=-1&&in[0][j-1][pa]>=in[1][j-1][i]) in[0][j][i]=in[0][j-1][i],in[1][j][i]=in[1][j-1][pa];
            else in[0][j][i]=in[1][j][i]=-1;
            if(de[0][j-1][i]!=-1&&de[0][j-1][pa]!=-1&&de[0][j-1][pa]<=de[1][j-1][i]) de[0][j][i]=de[0][j-1][i],de[1][j][i]=de[1][j-1][pa];
            else de[0][j][i]=de[1][j][i]=-1;
        }
}
bool ina,inb,dea,deb;
int A,B,a,b;
void up(int i){
    inb&= in[0][i][b]!=-1&&(B==0||in[0][i][b]>=B);
    deb&= de[0][i][b]!=-1&&(B==0||de[0][i][b]<=B);
    ina&= in[0][i][a]!=-1&&(A==0||in[0][i][a]>=A);
    dea&= de[0][i][a]!=-1&&(A==0||de[0][i][a]<=A);
    if(inb) B=in[1][i][b];
    if(ina) A=in[1][i][a];
    if(deb) B=de[1][i][b];
    if(dea) A=de[1][i][a];
    a=lca[i][a],b=lca[i][b];
}
bool LCA(){
    ina=inb=dea=deb=1; A=B=0;
    if(dep[a]>dep[b]) swap(a,b);
    for(int i=dep[b]-dep[a],k=0;i;i>>=1,++k)
        if(i&1){
            inb&= in[0][k][b]!=-1&&(B==0||in[0][k][b]>=B);
            deb&= de[0][k][b]!=-1&&(B==0||de[0][k][b]<=B);
            if(inb) B=in[1][k][b];
            if(deb) B=de[1][k][b];
            b=lca[k][b];
        }
    for(int i=17;~i;--i) if(lca[i][a]!=lca[i][b]) up(i);
    if(a==b) return inb||deb;
    up(0);
    return (ina&&deb&&A<=B)||(inb&&dea&&A>=B);
}
int main(){Rosario
    cin>>n>>q;
    int x,y,c;
    memset(in,-1,sizeof(in)); memset(de,-1,sizeof(de));
    REP(i,n-1) cin>>x>>y>>c,add(x,y,c),add(y,x,c);
    lca[0][1]=1; dep[1]=1; dfs(1); build();
    //REP1(j,1,n) REP1(i,0,1) cout<<de[0][i][j]<<' '<<de[1][i][j]<<" \n"[i==1];
    while(q--){
        cin>>a>>b;
        cout<<(LCA()?"YES":"NO")<<"\n";
    }
    return 0;
}
