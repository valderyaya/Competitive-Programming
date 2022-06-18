//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,ans=0;
pii a[105];
int main(){//Rosario
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    a[n]=a[0];
    REP(i,n) ans+=a[i].F*a[i+1].S-a[i+1].F*a[i].S;
    cout<<abs(ans)/2<<"\n";
    return 0;
}
