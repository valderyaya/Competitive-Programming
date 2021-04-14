//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=1e6+5;
int cnt[z],a,b;
int main(){Rosario
    REP1(i,2,z-5) if(!cnt[i]) for(int j=i;j<z;j+=i) ++cnt[j];
    while(cin>>a>>b){
        int mx=0,ans;
        REP1(i,a,b)
            if(cnt[i]>mx) mx=cnt[i],ans=i;
        cout<<ans<<' '<<mx<<"\n";
    }
    return 0;
}
