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

int n,x,y,mxx=0,mxy=0,mnx=1e9,mny=1e9;
int main(){//Rosario
    cin>>n; int a,b;
    while(n--){
        cin>>a>>b;
        x=a+b,y=a-b;
        mxx=max(mxx,x);
        mxy=max(mxy,y);
        mnx=min(mnx,x);
        mny=min(mny,y);
    }
    cout<<max(mxx-mnx,mxy-mny)<<"\n";
    return 0;
}
