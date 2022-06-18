//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n;
pii a[20005];
int main(){//Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i].F>>a[i].S;
    sort(a+1,a+1+n);
    int x=a[1].F+a[n].F,y=a[1].S+a[n].S;
    for(int i=1,j=n;i<=j;++i,--j)
        if(a[i].F+a[j].F!=x||a[i].S+a[j].S!=y) return cout<<"This is a dangerous situation!\n",0;
    cout<<fixed<<setprecision(1)<<"V.I.P. should stay at ("<<(double)x/2<<','<<(double)y/2<<").";
    return 0;
}
