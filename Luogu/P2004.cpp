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

ll n,m,c,x,y,mx=0,a[1005][1005]={};
int main(){Rosario
    cin>>n>>m>>c;
    REP1(i,1,n) REP1(j,1,m) cin>>a[i][j],a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(int i=1;i<=n-c+1;i++){
        for(int j=1;j<=m-c+1;j++){
            ll sum=a[i+c-1][j+c-1]-a[i+c-1][j-1]-a[i-1][j+c-1]+a[i-1][j-1];
            if(sum>mx) mx=sum,x=i,y=j;
        }
    }
    cout<<x<<' '<<y<<"\n";
//    system("pause");
    return 0;
}
