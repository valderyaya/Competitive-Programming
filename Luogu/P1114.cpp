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

int s1=0,s2=0,x,n,a[200005],b[200005];
int main(){Rosario
    cin>>n;
    REP1(i,1,n){cin>>x;
        s1+=(x==1),s2+=(x==0);
        x=s1-s2+n;
        if(!a[x]&&x!=n) a[x]=i;
        else b[x]=i;
    }x=0;
    REP1(i,1,n+n) x=max(x,b[i]-a[i]);
    cout<<x<<"\n";
    return 0;
}
