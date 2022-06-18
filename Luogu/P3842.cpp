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

const int z=2e4+5;
int n,f[2][z];
pii a[z];
int dis(int x){return abs(a[x].S-a[x].F);}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i].F>>a[i].S;
    f[0][1]=1e9,f[1][1]=a[1].S-1;
    REP1(i,2,n){
        f[0][i]=1+min(f[0][i-1]+dis(i)+abs(a[i-1].F-a[i].S),f[1][i-1]+dis(i)+abs(a[i-1].S-a[i].S));
        f[1][i]=1+min(f[0][i-1]+dis(i)+abs(a[i-1].F-a[i].F),f[1][i-1]+dis(i)+abs(a[i-1].S-a[i].F));
    }cout<<min(f[0][n]+abs(n-a[n].F),f[1][n]+abs(a[n].S-n))<<"\n";
    return 0;
}
