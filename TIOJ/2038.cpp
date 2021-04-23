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

const int z=5e3+5,inf=1e9;
int n,m,d[z]={},p[z],sz[z];
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
int un(int a,int b){
    if(a==b) return sz[b];
    if(sz[a]>sz[b]) swap(a,b);
    p[a]=b; sz[b]+=sz[a];
    return sz[b];
}
vector<int> v[z];
vector<pii> jk;
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) p[i]=i,sz[i]=1;
    int a,b;
    REP(i,m) cin>>a>>b,v[a].em(b),v[b].em(a),d[a]++,d[b]++;
    for(queue<int> q;;){
        int mi=inf;
        REP1(i,1,n) if(d[i]) mi=min(mi,d[i]);
        if(mi==inf) break;
        REP1(i,1,n) if(d[i]==mi) d[i]=0,q.emplace(i);
        while(!q.empty()){
            a=q.front(); q.pop();
            jk.em(mkp(a,mi));
            for(auto &i:v[a])
                if(d[i]&&--d[i]<=mi) d[i]=0,q.emplace(i); 
        }
    }
    int ans=0;
    for(int i=jk.size()-1;~i;--i){
        tie(a,b)=jk[i]; d[a]=1;
        for(auto &i:v[a]) if(d[i]) ans=max(ans,b*un(fin(a),fin(i)));
    }cout<<ans<<"\n";
    return 0;
}
