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

int n,a[1050][1050];
void dfs(int x,int y,int x2,int y2){
    if(x==x2&&y==y2) return;
    int o=(x2-x+1)/2;
    REP1(i,x,x+o-1) REP1(j,y,y+o-1) a[i][j]=0;
    dfs(x+o,y,x2,y+o-1); 
    dfs(x,y+o,x+o-1,y2); 
    dfs(x+o,y+o,x2,y2);
}
signed main(){Rosario
    cin>>n;
    n=(1<<n);
    REP1(i,1,n) REP1(j,1,n) a[i][j]=1;
    dfs(1,1,n,n);
    REP1(i,1,n) REP1(j,1,n) cout<<a[i][j]<<" \n"[j==n];
    return 0;
}
