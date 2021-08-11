#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
// #define lb(x) (x&-x)

int n,m,sum=0,mul,x,g;
int main(){Rosario
    cin>>n>>m;
    mul=n*m;
    for(int i=n;i<=m;i+=n){
        x=mul/i;g=__gcd(x,i);
        if((x*i==mul)&&(g==n)&&(x*i/g==m)) sum++;
    }cout<<sum<<"\n";
//    system("pause");
    return 0;
}
