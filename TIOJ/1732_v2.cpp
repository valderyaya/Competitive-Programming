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

int n,a[100005],b[100005],c[100005];
int main(){Rosario
    while(cin>>n){
        REP1(i,1,n) cin>>a[i],b[i]=a[i];
        sort(b+1,b+1+n);
        REP1(i,1,n) c[i]=c[i-1]+b[i];
        int ans=2147483647;
        REP1(i,1,n){
            int k=lower_bound(b+1,b+1+n,a[i])-b;
            ans=min(ans,k*a[i]-c[k]+c[n]-c[k]-a[i]*(n-k));
        }   
        cout<<ans<<"\n";
    }
    return 0;
}
