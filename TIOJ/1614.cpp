//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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

int sum=0,a[100005],b[100005],n,m;
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    REP(i,m) cin>>b[i];
    sort(a,a+n),sort(b,b+m);
    int j=0;
    REP(i,n){
        int x=upper_bound(b,b+m,a[i])-b;
        if(x>0&&b[x-1]==a[i]) continue;
        sum+=(m-x)&1?0:1;
    }cout<<sum<<"\n";
//    system("pause");
    return 0;
}
