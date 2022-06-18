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

uint64_t n,m;
pair<uint64_t,uint64_t> a[100005];
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i].F>>a[i].S;
    sort(a,a+n);
    uint64_t sum=0;
    REP(i,n){
        if(m>=a[i].F*a[i].S) m-=a[i].F*a[i].S,sum+=a[i].S;
        else{
            sum+=m/a[i].F;
            break;
        }
    }
    cout<<sum;
    return 0;
}
