//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int f(int n,int x,int y){
    if(n==0) return 0;
    int t=1<<(n-1);
    if(x>=t&&y>=t) return f(n-1,x-t,y-t)^1;
    if(x>=t) x-=t;
    if(y>=t) y-=t;
    return f(n-1,x,y);
}
int main(){Rosario
    int n,i,a,b;
    while(cin>>n>>i>>a>>b)
        REP1(j,a,b) cout<<(f(n,i-1,j-1)?"+1":"-1")<<" \n"[j==b];
    return 0;
}
