//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=3e5+5;
int dis[z],lca[22][z],n,m,s[z],l,r,dep[z],num[z],tot;
struct QAQ{int u,v,ac,d;}qwq[z];
vector<pii> v[z];
void dfs(int x,int p){
    ++tot;
    num[tot]=x;
    for(auto &i:v[x])
        if(i.F!=p){
            lca[0][i.F]=x;
            dis[i.F]=dis[x]+i.S;
            dep[i.F]=dep[x]+1;
            dfs(i.F,x);
        }
}
void bulid(){
    for(int j=1;j<22;++j)
        for(int i=1;i<=n;++i)
            lca[j][i]=lca[j-1][lca[j-1][i]];
}
int LCA(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    for(int i=dep[b]-dep[a],k=0;i;i>>=1,++k) if(i&1) b=lca[k][b];
    if(a==b) return a;
    for(int i=21;~i;--i) if(lca[i][a]!=lca[i][b]) a=lca[i][a],b=lca[i][b];
    return lca[0][a];
}
bool ck(int mid){
    memset(s,0,sizeof(s));
    int cnt=0,ans=0;
    REP(i,m) if(qwq[i].d>mid){
        ++cnt,++s[qwq[i].u],++s[qwq[i].v],s[qwq[i].ac]-=2;
        ans=max(ans,qwq[i].d-mid);
    }
    if(cnt==0) return 1;
    for(int i=n;i;--i) s[lca[0][num[i]]]+=s[num[i]];
    REP1(i,2,n) if(s[i]==cnt&&dis[i]-dis[lca[0][i]]>=ans) return 1;
    return 0;
}
int main(){Rosario
    cin>>n>>m;
    int x,y,c;
    REP(i,n-1){
        cin>>x>>y>>c;
        v[x].pb({y,c});
        v[y].pb({x,c});
        r+=c;
    }
    lca[0][1]=1; dfs(1,1); bulid();
    REP(i,m){
        cin>>qwq[i].u>>qwq[i].v;
        qwq[i].ac=LCA(qwq[i].u,qwq[i].v);
        //cout<<qwq[i].u<<' '<<qwq[i].v<<' '<<qwq[i].ac<<endl;
        qwq[i].d=dis[qwq[i].u]+dis[qwq[i].v]-2*dis[qwq[i].ac];
    }
    while(l<r){
        x=l+r>>1;
        if(ck(x)) r=x;
        else l=x+1;
    }
    cout<<l<<"\n";
    return 0;
}
