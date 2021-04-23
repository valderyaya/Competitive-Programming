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

char ans[2200][2200];
void dfs(int x,int y,int xx,int yy){
    if(x==xx&&y==yy) return ans[x][y]='.',void();
    int d=(xx-x+1)/3;
    for(int i=x+d-1;i<x+d+d;++i) for(int j=y+d-1;j<y+d+d;++j) ans[i][j]='#';
    dfs(x,y,x+d-1,y+d-1); dfs(x,y+d,x+d-1,y+d+d-1); dfs(x,y+d+d,x+d-1,yy);
    dfs(x+d,y,x+d+d-1,y+d-1); dfs(x+d,y+d+d,x+d+d-1,yy);
    dfs(x+d+d,y,xx,y+d-1); dfs(x+d+d,y+d,xx,y+d+d-1); dfs(x+d+d,y+d+d,xx,yy);
}
int main(){Rosario
    int n,N;
    cin>>n; N=pow(3,n);
    dfs(1,1,N,N);
    REP1(i,1,N) {
        REP1(j,1,N) cout<<ans[i][j];
        cout<<"\n";
    }
    return 0;
}
