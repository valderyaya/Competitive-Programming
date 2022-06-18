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

int sum=0,n,a[3],b[3];
bool ck(int x,int y){
    if(abs(x-y)>=n-2||abs(x-y)<=2) return 1;
    return 0;
}
int main(){Rosario
    cin>>n;
    REP(i,3) cin>>a[i];
    REP(i,3) cin>>b[i];
    REP1(i,1,n)
        REP1(j,1,n)
            REP1(k,1,n)
                if(ck(a[0],i)&&ck(a[1],j)&&ck(a[2],k)) ++sum;
                else if(ck(b[0],i)&&ck(b[1],j)&&ck(b[2],k)) ++sum;
    cout<<sum<<"\n";
    return 0;
}
