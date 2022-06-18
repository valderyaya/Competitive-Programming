//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e5+5;
int n,f[z][2],dp[z][2],qe[z],idx,in[z],ans;
double k;
vector<int> v[z];
bitset<z> is;
void dfs_(int x,int p){
    for(auto &i:v[x]){
        if(i==p||is[i]||in[i]!=2) continue;
        qe[++idx]=i; is[i]=1;
        dfs_(i,x);
    }
}
void topo(){
    queue<int> q;
    REP1(i,1,n) if(in[i]==1) q.emplace(i);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(auto &i:v[x]) if(--in[i]==1) q.emplace(i);
    }
    REP1(i,1,n) if(in[i]==2){qe[++idx]=i; is[i]=1; dfs_(i,i); break;}
}
void dfs(int x,int p){
    for(auto &i:v[x]){
        if(i==p||is[i]) continue;
        dfs(i,x);
        f[x][0]+=max(f[i][0],f[i][1]);
        f[x][1]+=f[i][0];
    }
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>f[i][1];
    for(int x,y,i=0;i<n;++i) cin>>x>>y,++x,++y,v[x].em(y),v[y].em(x),++in[x],++in[y];
    topo();
    REP1(i,1,idx) dfs(qe[i],0);
    dp[1][0]=f[qe[1]][0];
    REP1(i,2,idx){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+f[qe[i]][0];
        dp[i][1]=dp[i-1][0]+f[qe[i]][1];
    } 
    ans=max(dp[idx][0],dp[idx][1]);
    memset(dp,0,sizeof(dp));
    dp[1][1]=f[qe[1]][1];
    REP1(i,2,idx){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+f[qe[i]][0];
        dp[i][1]=dp[i-1][0]+f[qe[i]][1];
    }
    ans=max(ans,dp[idx][0]);
    cin>>k;
    cout<<fixed<<setprecision(1)<<k*ans<<"\n";
    return 0;
}
