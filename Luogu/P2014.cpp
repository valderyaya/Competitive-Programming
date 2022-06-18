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

int f[305][305],n,m,val[305];
vector<int> v[305];
void dfs(int x){
    f[x][1]=val[x];
    for(auto &to:v[x]){
        dfs(to);
        for(int i=m;i;--i) for(int j=i-1;j;--j) f[x][i]=max(f[x][i],f[x][i-j]+f[to][j]);
    }
}
int main(){Rosario
    cin>>n>>m;
    for(int x,y,i=1;i<=n;++i){
        cin>>x>>val[i];
        v[x].em(i);
    }++m;
    dfs(0);
    cout<<f[0][m];
    return 0;
}
