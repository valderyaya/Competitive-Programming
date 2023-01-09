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
 
int n,x;
signed main(){Aincrad
    cin>>n;
    for(int i=1;i<=(1<<n);++i){
        for(int j=n-1;~j;--j) cout<<(x>>j&1);
        cout<<"\n";
        if(i&1) x^=1;
        else for(int j=0;;++j) if(x>>j&1) {x^=(1<<(j+1));break;}
    }
    return 0;
}
