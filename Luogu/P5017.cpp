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

int n,m,a[505],f[505][205];
int dfs(int i,int t){
    if(i>n) return 0;
    if(a[i]>t) return dfs(i,a[i]);
    if(f[i][t-a[i]]) return f[i][t-a[i]];
    int s=0,j=i,res;
    while(j<=n&&a[j]<=t) s+=a[j++];
    res=t*(j-i)-s+dfs(j,t+m);
    for(;j<=n;++j){
        s+=a[j];
        res=min(res,a[j]*(j-i+1)-s+dfs(j+1,a[j]+m));
    }
    return f[i][t-a[i]]=res;
}
signed main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    cout<<dfs(1,0)<<'\n';
    return 0;
}
