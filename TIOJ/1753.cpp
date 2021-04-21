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

const int z=3e5+5;
int n,even,odd,now=0;
pii a[z],b[z];
ll sum=0;
bool cmp(pii x,pii y){return x.F<y.F;}
int main(){Rosario
    cin>>n; int x,y;
    REP(i,n){
        cin>>x>>y;
        if(y&1) b[odd++]=mkp(x,y);
        else a[even++]=mkp(x,y);
    }sort(a,a+even); sort(b,b+odd);
    REP(i,even){
        while(now<odd&&b[now].F<=a[i].F) ++now;
        sum+=odd-now;
    } now=0;
    REP(i,odd){
        while(now<even&&a[now].F<=b[i].F) ++now;
        sum+=even-now;
    } now=0;
    REP(i,odd){
        while(now<i&&b[now].F<b[i].F) ++now;
        sum+=now;
    } now=0;
    REP(i,even){
        while(now<i&&a[now].F<a[i].F) ++now;
        sum+=now;
    }
    cout<<sum<<"\n";
    return 0;
}
