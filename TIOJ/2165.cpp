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

ll n,m,a[500005],x,ck[500005];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i],a[i]+=a[i-1];
    REP1(i,1,n) for(int j=i;j<=n;++j){
        x=a[j]-a[i-1];
        if(x<=500000) ++ck[x];
        else break;
    }
    cin>>m;
    while(m--){
        cin>>x;
        cout<<ck[x]<<"\n";
    }
    return 0;
}
