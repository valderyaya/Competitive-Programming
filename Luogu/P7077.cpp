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


#define int ll
const int z=1e5+5,md=998244353;
int n,m,deg[z],a[z],q,mul[z],opt[z],pos[z],add[z],cnt[z];
vector<int> v1[z],v2[z];
void topo1(){
    queue<int> q;
    REP1(i,0,m){
        deg[i]=v2[i].size();
        if(!deg[i]) q.emplace(i);
    }
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &i:v1[x]){
            mul[i]=(mul[i]*mul[x])%md;
            if(--deg[i]==0) q.emplace(i);
        }
    }
}
void topo2(){
    queue<int> q;
    REP1(i,0,m){
        deg[i]=v1[i].size();
        if(deg[i]==0) q.emplace(i);
    }
    while(!q.empty()){
        int x=q.front(),ml=1; q.pop();
        for(int i=v2[x].size()-1;~i;--i){
            int v=v2[x][i];
            cnt[v]=(cnt[v]+cnt[x]*ml)%md;
            ml=(ml*mul[v])%md;
            if(--deg[v]==0) q.emplace(v);
        }
    }
}
signed main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    cin>>m; mul[0]=1;
    REP1(i,1,m){
        cin>>opt[i];
        if(opt[i]==1) cin>>pos[i]>>add[i],mul[i]=1;
        else if(opt[i]==2) cin>>mul[i];
        else{
            mul[i]=1;
            int x,v;
            cin>>x;
            while(x--) cin>>v,v1[v].em(i),v2[i].em(v);
        }
    }
    cin>>q;  cnt[0]=1;
    for(int x,i=0;i<q;++i) cin>>x,v2[0].em(x),v1[x].em(0);
    topo1();
    topo2();
    REP1(i,1,n) a[i]=(a[i]*mul[0])%md;
    REP1(i,1,m) if(opt[i]==1) a[pos[i]]=(a[pos[i]]+cnt[i]*add[i])%md;
    REP1(i,1,n) cout<<a[i]<<" \n"[i==n];    
    return 0;
}
