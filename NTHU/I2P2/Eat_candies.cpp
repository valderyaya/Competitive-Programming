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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll t,a,b,c;
signed main(){Aincrad
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        if(a>b) a^=b^=a^=b;
        if(b>c) swap(b,c);
        if(a>c) swap(a,c);
        if(c-b>=a) cout<<a+b<<"\n";
        else{
            a-=c-b;
            b=c;
            cout<<b+a/2<<"\n";
        }
    }
    return 0;
}
