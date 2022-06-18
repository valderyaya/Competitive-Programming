//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
#include<bits/extc++.h>
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

int x,a[1005],y,n,m,mod[]={1,10,100,1000,10000,100000,1000000,10000000};
int ret(){
    REP(i,n) if(a[i]%mod[x]==y) return a[i];
    return -1;
}
int main(){Rosario
   cin>>n>>m;
   REP(i,n) cin>>a[i];
   sort(a,a+n);
   while(m--) cin>>x>>y,cout<<ret()<<"\n";
//    system("pause");
    return 0;
}
