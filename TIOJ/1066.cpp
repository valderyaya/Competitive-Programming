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


int main(){Rosario
    int t,n,p[]={1,5,10,20,50};
    cin>>t;
    while(t--){
        int cnt=0,sum,a[5]={},b[5]={};
        cin>>sum; sum=-sum;
        REP(i,5) cin>>a[i],sum+=a[i]*p[i];
        REP(i,5) cin>>b[i],b[i]+=a[i];
        for(int i=4;~i;--i){
            int x=min(sum/p[i],b[i]);
            sum-=x*p[i]; cnt+=x;
        }cout<<cnt<<"\n";
    }
    return 0;
}
