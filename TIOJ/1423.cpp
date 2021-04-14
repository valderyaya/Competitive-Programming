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

int n,ans;
pii a[360];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    REP(i,n) for(int j=i+1;j<n;++j){
        int c1=0,c2=0;
        REP(k,n) if(k!=i&&k!=j){
            int x=a[j].S-a[i].S, y=a[i].F-a[j].F, c=a[j].F*a[i].S-a[i].F*a[j].S;
            int f=x*a[k].F+y*a[k].S+c;
            if(f>0) ++c1;
            if(f<0) ++c2;
        }
        ans+=c1*c2;
    }
    cout<<ans<<"\n";
    return 0;
}
