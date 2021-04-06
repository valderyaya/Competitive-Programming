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

int n,m,x[101],y[101],a,sum=0;
int main(){Rosario
    cin>>n>>m;
    REP(i,n) REP(j,m) cin>>a,x[i]+=a,y[j]+=a,sum+=a;
    sum=(sum+1)>>1; a=0;
    REP(i,n) 
        if(a+x[i]<sum) a+=x[i];
        else {cout<<i+1<<' ';break;}
    a=0;
    REP(i,m)
        if(a+y[i]<sum) a+=y[i];
        else {cout<<i+1<<' ';break;}
    return 0;
}
