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

const int inf=1e9;
int tot=0;
struct matrix{
    ll c[252][252];
    ll* operator[](int x){return c[x];}
    void set(ll x){REP1(i,1,250) REP1(j,1,250) c[i][j]=x;}
}pw[31];
matrix operator*(matrix x,matrix y){
    matrix res; res.set(-inf);
    REP1(i,1,tot) REP1(j,1,tot) REP1(k,1,tot) res[i][j]=max(res[i][j],x[i][k]+y[k][j]);
    return res;
}
struct cel{
    int t,x,v;
    bool operator<(const cel &a)const{return t<a.t;}
}ac[205];
int cost[55],n,m,t,k,id[55][6];
ll a[255];
void mul(int p){
    ll c[255];
    REP1(i,1,tot) c[i]=-inf;
    REP1(i,1,tot) REP1(j,1,tot) c[i]=max(c[i],a[j]+pw[p][j][i]);
    REP1(i,1,tot) a[i]=c[i];
}
int main(){Rosario
    cin>>n>>m>>t>>k;
    pw[0].set(-inf);
    REP1(i,1,n) id[i][0]=++tot;
    REP1(i,1,n) cin>>cost[i];
    for(int x,y,w,i=1;i<=m;++i){
        cin>>x>>y>>w;
        REP1(j,1,w-1) if(!id[x][j]) id[x][j]=++tot;
        REP1(j,1,w-1) pw[0][id[x][j-1]][id[x][j]]=0;
        pw[0][id[x][w-1]][y]=cost[y];
    }
    REP1(i,1,k) cin>>ac[i].t>>ac[i].x>>ac[i].v;
    sort(ac+1,ac+k+1); ac[0]=cel{0,0,0}, ac[k+1]=cel{t,0,0};
    REP1(i,1,30) pw[i]=pw[i-1]*pw[i-1];
    REP1(i,2,tot) a[i]=-inf;   a[1]=cost[1];
    REP1(i,1,k+1){
        int df=ac[i].t-ac[i-1].t;
        for(int j=30;~j;--j) if(df>>j&1) mul(j);
        a[ac[i].x]+=ac[i].v;
    }
    if(a[1]<0) cout<<"-1\n";
    else cout<<a[1]<<"\n";
    return 0;
}
