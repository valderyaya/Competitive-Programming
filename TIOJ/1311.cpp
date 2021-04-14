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


inline void rd(int &x){
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
int main(){//Rosario
    int n,x1,x2,y1,y2;
    while(rd(n),n){
        rd(x1),rd(x2),rd(y1),rd(y2);
        for(;y1<=y2;++y1){
            int x=__gcd(y1,n);
            for(int i=x1;i<=x2;++i) putchar((__gcd(i,x)==1?'*':'.'));
            puts("");
        }
        puts("--");
    }
    return 0;
}
